#include "RTPI_ControlPanel.h"

void RTPI_ControlPanel::ColourMatcher(){
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
    m_colorMatcher.AddColorMatch(kFakeYellowTarget1);
    preColorString = "Unknown";
}

void RTPI_ControlPanel::ColourAndCount(){
  frc::Color detectedColor = m_colorSensor.GetColor();  
  frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    if (matchedColor == kBlueTarget) {
      if(preColorString == "Yellow") {
        colorCount++;
      }
      else if(preColorString == "Green") {
        colorCount--;
      }

      colorString = "Blue";
      preColorString = "Blue";

    } 
    
    else if (matchedColor == kRedTarget) {
    if(preColorString == "Green") {
      colorCount++;
    }
    else if(preColorString == "Yellow") {
      colorCount--;
     }

      
   preColorString = "Red";
    colorString = "Red";
    } 
    
    else if (matchedColor == kGreenTarget) {
    if(preColorString == "Blue") {
      colorCount++;
    }
    else if(preColorString == "Red") {
      colorCount--;
     }

      
   preColorString = "Green";
    colorString = "Green";
    } 
    
    else if (matchedColor == kYellowTarget) {
     if(preColorString == "Red") {
      colorCount++;
    }
    else if(preColorString == "Blue") {
      colorCount--;
     }

      
   preColorString = "Yellow";
    colorString = "Yellow";
    } 

    else if (matchedColor == kFakeYellowTarget1) {
    colorString = "fake yellow";
    }

    else {
      colorString = "Unknown";
    }

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("colourcount", colorCount);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
    frc::SmartDashboard::PutString("precolourstring", preColorString);
    frc::SmartDashboard::PutString("colourstring", colorString);
}
