#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// 리플렉션을 위한 인터페이스 수정을 할 필요 없음
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

class TASK8_API IItemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION() // 런타임때 함수를 찾을 수 있다
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, // 자기 자신
		AActor* OtherActor, // Sphere 컴포넌트에 부딪친 액터
		UPrimitiveComponent* OtherComp, // OtherActor에 붙어있는 충돌원인 컴포넌트
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0; // FName -> 타입형을 알아낼 때  사용 string이 생각보다 무거움
};

