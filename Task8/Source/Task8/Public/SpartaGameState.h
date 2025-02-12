#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"

UCLASS()
class TASK8_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()

public:
	ASpartaGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	float WaveDuration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentWaveIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxWaves;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Level")
	TArray<int32> ItemToSpawn;
	
	FTimerHandle LevelTimer;
	FTimerHandle WaveTimer;
	FTimerHandle HUDUpdateTimerHandle;
	
	UFUNCTION(BlueprintPure, Category= "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category= "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category= "Level")
	void OnGameOver();

	void StartLevel();
	void StartWave(int32 Wave);
	void OnLevelTimeUp();
	void OnWaveTimeUp();
	void OnCoinCollected();
	void EndLevel();
	void EndWave();
	void RemoveAllItems();
	void UpdateHUD();
	void StartHUD();
};
