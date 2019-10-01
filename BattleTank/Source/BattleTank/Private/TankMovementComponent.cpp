#include "BattleTank.h"
#include "tanktrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RighTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RighTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto TankDotProduct = FVector::DotProduct(TankForward, AIForwardIntention);

	IntendMoveForward(TankDotProduct);
	//UE_LOG(LogTemp, Warning, TEXT("%s is moving at velocity: %s"), *TankName, *MoveVelocityString);

	auto TankCrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(TankCrossProduct);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}