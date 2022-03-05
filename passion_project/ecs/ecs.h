//
//  entity.hpp
//  passion_project
//
//  Created by Andrew Kuhl on 3/4/22.
//

#ifndef ecs_h
#define ecs_h

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;

class Entity;

using ComponentID = std::size_t;

inline ComponentID get_component_type_id()
{
    static ComponentID last_id = 0;
    return last_id++;
}

template <typename T> inline ComponentID get_component_type_id() noexcept
{
    static ComponentID type_id = get_component_type_id();
    return type_id;
}

constexpr std::size_t Max_Components = 32;

using ComponentBitSet = std::bitset<Max_Components>;
using ComponentArray = std::array<Component*, Max_Components>;

class Component
{
public:
    Entity* entity;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    
    virtual ~Component() {}
};

class Entity
{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray component_array;
    ComponentBitSet component_bit_set;

public:
    void update()
    {
        for(auto& c : components) c->update();
    }
    void draw()
    {
        for(auto& c : components) c->draw();
    }
    
    bool is_active() { return active;}
    
    void destroy() { active = false;}
    
    template <typename T> bool has_component() const
    {
        return component_bit_set[get_component_type_id<T>];
    }
    
    template <typename T, typename... TArgs>
    T& add_component(TArgs && ... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));
        
        component_array[get_component_type_id<T>()] = c;
        component_bit_set[get_component_type_id<T>()] = true;
        
        c->init();
        return *c;
    }
    
    template <typename T> T& get_component() const
    {
        auto &ptr(component_array[get_component_type_id<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;
    
public:
    void update()
    {
        for(auto &e : entities) e->update();
    }
    void draw()
    {
        for(auto &e : entities) e->draw();
    }
    void refresh()
    {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                      [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->is_active();
        }),
                       std::end(entities));
    }
    Entity& add_entity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr { e };
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};

#endif /* ecs_h */
