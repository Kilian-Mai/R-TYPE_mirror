#pragma once

#include <any>
#include <typeindex>
#include <memory>
#include <unordered_map>
#include "Types.hpp"

template <typename T>
class Component
{
public:
    ComponentType                   mType;
    std::unordered_map<Entity, T>   mEntitiesData;

public:
    T& GetEntityData(Entity entity)
    {
        return mEntitiesData[entity];
    }

    void EntityCreate(Entity entity, T data)
    {
        mEntitiesData.insert(entity, daa);
    }

    void EntityDestroyed(Entity entity)
    {
        mEntitiesData.erase(entity);
    }
};

class ComponentManager
{
public:

    /**
     * @brief Registers a new component and assigns it the next available component ID.
     *
     * @tparam T Component
     */
    template <typename T>
    void RegisterComponent()
    {
        assert((mComponents.find(typeid(T)) == mComponents.end()) && "Registering component type more than once.");

        auto component = new Component<T>();

        component->mType = mComponents.size();
        mComponents.insert({ typeid(T), component });
    }

    /**
     * @brief Attach component data to a new Entity.
     *
     * @tparam T 
     * @param entity 
     * @param component 
     */
    template <typename T>
    void AddComponent(Entity entity, T component)
    {
        GetComponent<T>()->EntityCreate(entity, component);
    }

    template <typename T>
    void RemoveComponent(Entity entity)
    {
        GetComponent<T>()->EntityDestroyed(entity);
    }

    template <typename T>
    T& GetComponentData(Entity entity)
    {
        return GetComponent<T>()->GetEntityData(entity);
    }

    template <typename T>
    ComponentType GetComponentType()
    {
        return GetComponent<T>()->mType;
    }

    void EntityDestroyed(Entity entity)
    {
        for (auto const &pair : mComponents) {
            (pair.second)->EntityDestroyed(entity);
        }
    }

private:
    template <typename T>
    std::shared_ptr<Component<T>> GetComponent()
    {
        assert(mComponents.find(typeid(T)) != mComponents.end() && "Component not registered before use.");

        return std::static_pointer_cast<Component<T>>(mComponents[typeid(T)]);
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<Component<std::any>>> mComponents{};
};
