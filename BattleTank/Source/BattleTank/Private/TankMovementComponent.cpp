#include "BattleTank.h"
#include "tanktrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RighTrackToSet)
{
	if (!LeftTrackToSet || !RighTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RighTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}