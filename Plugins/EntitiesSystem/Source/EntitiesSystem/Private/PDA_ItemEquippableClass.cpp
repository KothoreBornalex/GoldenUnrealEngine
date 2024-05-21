// Fill out your copyright notice in the Description page of Project Settings.


#include "PDA_ItemEquippableClass.h"

UAnimMontage* UPDA_ItemEquippableClass::GetEquippableAnimMontage(EEquippableAnimMontages EquippableAnimInstance)
{
    return *AnimMontagesMap.Find(EquippableAnimInstance);
}
