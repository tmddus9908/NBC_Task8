#include "HealingItem.h"

#include "SpartaCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "SpartaPlayerController.h"

class UProgressBar;

AHealingItem::AHealingItem()
{
	HealAmount = 20;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator))
		{
			PlayerCharacter->AddHealth(HealAmount);
			
			if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
			{
				if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
				{
					if (UUserWidget* HUDWidget = SpartaPlayerController->GetHUDWidget())
					{
						if (UProgressBar* HealthProgress = Cast<UProgressBar>(HUDWidget->GetWidgetFromName(TEXT("Health"))))
						{
							HealthProgress->SetPercent(PlayerCharacter->GetHealth() / 100.0f);
						}
					}
				}
			}
		}
		DestroyItem();
	}
}
