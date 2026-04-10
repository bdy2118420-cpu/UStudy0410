// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyPlayerController.h"
AMyGameModeBase::AMyGameModeBase()
{
	//생성자 초기화 -->CDL(Class defult, objrct)초기화
	//에셋로딩 x
	//값만 초기화


	/*UE_LOG(LogTemp, Warning, TEXT("안녕하세요"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("안녕하세요"));
	}*/

	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}
