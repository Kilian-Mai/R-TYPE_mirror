/*
** EPITECH PROJECT, 2022
** B-CPP-500-STG-5-1-rtype-gabriel.ravier
** File description:
** RenderSystem
*/

#include "RenderSystem.hpp"
#include <iostream>

extern Coordinator gCoordinator;

void RenderSystem::Init() {}

void RenderSystem::Update(const std::shared_ptr<WindowManager> &windowManager) const
{
    windowManager->Clear();
    for (auto const &entity : mEntities) {
        auto const &transform = gCoordinator.GetComponent<Transform>(entity);
        auto const &sprite    = gCoordinator.GetComponent<Sprite>(entity);
        windowManager->RenderSprite(sprite.sprite, transform.position);
    }
}
