#pragma once
#include "Engine\\GameObject.h"

enum FoodType
{
    FOODTYPE_NORMAL,
    FOODTYPE_POWER,
    FOOD_TYPE_MAX

};

class Food :
    public GameObject
{
public:
    Food();
    ~Food();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    void SetFoodType(FoodType type) { type_ = type; }
    void OnCollision(GameObject* pTarget)override;
private:
    FoodType type_;
    int hModel_;
    int score_;

};

