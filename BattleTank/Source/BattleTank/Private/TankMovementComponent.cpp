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

	auto TankCrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(TankCrossProduct);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}