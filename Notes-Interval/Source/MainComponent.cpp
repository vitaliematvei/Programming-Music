#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	addAndMakeVisible(titleLabel);
	titleLabel.setFont(juce::Font(16.0f, juce::Font::bold));
	titleLabel.setText("Click in the white boxes to enter the notes (Ex. A and B) ", juce::dontSendNotification);
	titleLabel.setColour(juce::Label::textColourId, juce::Colours::black);


	addAndMakeVisible(inputFirstLabel);
	inputFirstLabel.setText("First Note input:", juce::dontSendNotification);
	inputFirstLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	inputFirstLabel.setJustificationType(juce::Justification::right);
	inputFirstLabel.attachToComponent(&inputFirstText, true);


	addAndMakeVisible(inputSecondLabel);
	inputSecondLabel.setText("Second Note input:", juce::dontSendNotification);
	inputSecondLabel.attachToComponent(&inputSecondText, true);
	inputSecondLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	inputSecondLabel.setJustificationType(juce::Justification::right);


	addAndMakeVisible(inputFirstText);
	inputFirstText.setEditable(true);
	inputFirstText.setColour(juce::Label::backgroundColourId, juce::Colours::white);
	inputFirstText.setColour(juce::Label::outlineColourId, juce::Colour(0, 120, 215));
	inputFirstText.setColour(juce::Label::textColourId, juce::Colours::black);
	inputFirstText.setColour(juce::Label::textWhenEditingColourId, juce::Colours::black);
	inputFirstText.setExplicitFocusOrder(0);


	addAndMakeVisible(inputSecondText);
	inputSecondText.setEditable(true);
	inputSecondText.setColour(juce::Label::backgroundColourId, juce::Colours::white);
	inputSecondText.setColour(juce::Label::outlineColourId, juce::Colour(0, 120, 215));
	inputSecondText.setColour(juce::Label::textColourId, juce::Colours::black);
	inputSecondText.setColour(juce::Label::textWhenEditingColourId, juce::Colours::black);
	inputSecondText.onTextChange = [this]
	{
		showResult.setText(calcInterval(), juce::dontSendNotification);
	};


	addAndMakeVisible(inervalLabel);
	inervalLabel.setText("Interval: ", juce::dontSendNotification);
	inervalLabel.setFont(juce::Font(16.0f, juce::Font::bold));
	inervalLabel.attachToComponent(&showResult, true);
	inervalLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	inervalLabel.setJustificationType(juce::Justification::right);


	addAndMakeVisible(showResult);
	showResult.setColour(juce::Label::backgroundColourId, juce::Colours::white);
	showResult.setColour(juce::Label::outlineColourId, juce::Colour(0, 120, 215));
	showResult.setColour(juce::Label::textColourId, juce::Colours::black);
	showResult.setColour(juce::Label::textWhenEditingColourId, juce::Colours::black);

	setSize(400, 210);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colour(240, 240, 240));
}

void MainComponent::resized()
{
	titleLabel.setBounds(10, 10, getWidth() - 20, 30);
	inputFirstText.setBounds(100, 50, getWidth() - 110, 20);
	inputSecondText.setBounds(100, 80, getWidth() - 110, 20);
	inervalLabel.setBounds(10, 110, getWidth() - 110, 30);
	showResult.setBounds(100, 110, getWidth() - 110, 20);
}

juce::String MainComponent::calcInterval()
{
	juce::String inputFirstNote = inputFirstText.getText().toUpperCase();
	juce::String inputSecondNote = inputSecondText.getText().toUpperCase();

	int pc1 = calcPitchClasses(inputFirstNote);
	int pc2 = calcPitchClasses(inputSecondNote);

	if (pc1 == -1)
		return "error: " + inputFirstNote + " is not a nutural note";
	else if (pc2 == -1)
		return "error: " + inputSecondNote + " is not a nutural note";


	int interval = pc2 - pc1;
	if (interval < 0)interval += 12;

	return returnInterval(interval);
}

int MainComponent::calcPitchClasses(juce::String str)
{
	int pos;

	if (str == "C") pos = 0;
	else
		if (str == "D") pos = 2;
		else
			if (str == "E") pos = 4;
			else
				if (str == "F")	pos = 5;
				else
					if (str == "G")	pos = 7;
					else
						if (str == "A")	pos = 9;
						else
							if (str == "B")	pos = 11;
							else return -1;

	return pos;
}

juce::String MainComponent::returnInterval(int interval)
{
	juce::String result;

	switch (interval)
	{
	case 1:
		result = "minor 2nd up or major 7th down"; break;
	case 2:
		result = "major 2nd up or minor 7th down"; break;
	case 3:
		result = "minor 3nd up or major 6th down"; break;
	case 4:
		result = "major 3nd up or minor 6th down"; break;
	case 5:
		result = "perfect 4th up or perfect 5th down"; break;
	case 6:
		result = "augmented 4th"; break;
	case 7:
		result = "perfect 5th up or perfect 4th down"; break;
	case 8:
		result = "minor 6th up or major 3rd down"; break;
	case 9:
		result = "major 6th up or minor 3rd down"; break;
	case 10:
		result = "minor 7th up or major 2rd down"; break;
	case 11:
		result = "major 7th up or minor 2rd down"; break;
	default:
		result = "unison"; break;
		break;
	}
	return result;
}
