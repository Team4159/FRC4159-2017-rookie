#include "OI.h"

#include <WPILib.h>
#include <Buttons/JoystickButton.h>
#include "Commands/Shoot.h"
OI::OI() {
	AimButton = new JoystickButton(leftStick.get(),1);
	AimButton->WhenPressed(new AutoAim());
	shootButton = new JoystickButton(rightStick.get(), 1);
	shootButton->WhileHeld(new Shoot());
	GearButton = new JoystickButton(rightStick.get(), 2);
	GearButton->WhenPressed(new AutoGear());
}

double OI::GetLeftDriveValue(){
	return leftStick->GetAxis(LEFT_DRIVE_AXIS) * LEFT_DRIVE_MULTIPLIER;
}

double OI::GetRightDriveValue(){
	return rightStick->GetAxis(RIGHT_DRIVE_AXIS) * RIGHT_DRIVE_MULTIPLIER;
}

double OI::GetFlywheelValue(){
	return FLYWHEEL_DEFAULT + (rightStick->GetAxis(FLYWHEEL_AXIS) * -1 * (-1 - FLYWHEEL_DEFAULT));
}

double OI::GetTurnValue(){
	return leftStick->GetAxis(SHOOTING_TURN_AXIS) * SHOOTING_TURN_MULTIPLIER;
}
