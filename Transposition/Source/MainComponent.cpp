#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{

	//===========================Note input=====================================
	addAndMakeVisible(noteLabel);
	noteLabel.setFont(juce::Font(12.0f));
	noteLabel.setText("Enter base note (use # for sharps, eg. A#): ", juce::dontSendNotification);
	noteLabel.setColour(juce::Label::textColourId, juce::Colours::black);

	addAndMakeVisible(inputNoteLabel);
	inputNoteLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	inputNoteLabel.setJustificationType(juce::Justification::right);
	inputNoteLabel.attachToComponent(&inputNoteText, true);

	addAndMakeVisible(inputNoteText);
	inputNoteText.setEditable(true);
	inputNoteText.setColour(juce::Label::backgroundColourId, juce::Colours::white);
	inputNoteText.setColour(juce::Label::outlineColourId, juce::Colour(0, 120, 215));
	inputNoteText.setColour(juce::Label::textColourId, juce::Colours::black);
	inputNoteText.setColour(juce::Label::textWhenEditingColourId, juce::Colours::black);
	inputNoteText.setExplicitFocusOrder(0);


	//===========================Interval input===================================
	addAndMakeVisible(intervalLabel);
	intervalLabel.setFont(juce::Font(12.0f));
	intervalLabel.setText("Enter interval in semitones: ", juce::dontSendNotification);
	intervalLabel.setColour(juce::Label::textColourId, juce::Colours::black);

	addAndMakeVisible(inputIntervalLabel);
	inputIntervalLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	inputIntervalLabel.setJustificationType(juce::Justification::right);
	inputIntervalLabel.attachToComponent(&inputIntervalText, true);

	addAndMakeVisible(inputIntervalText);
	inputIntervalText.setEditable(true);
	inputIntervalText.setColour(juce::Label::backgroundColourId, juce::Colours::white);
	inputIntervalText.setColour(juce::Label::outlineColourId, juce::Colour(0, 120, 215));
	inputIntervalText.setColour(juce::Label::textColourId, juce::Colours::black);
	inputIntervalText.setColour(juce::Label::textWhenEditingColourId, juce::Colours::black);
	inputIntervalText.setExplicitFocusOrder(1);


	//===========================Button ot calculate===============================
	addAndMakeVisible(calculateBtn);
	calculateBtn.setColour(juce::TextButton::buttonColourId, juce::Colours::grey);
	calculateBtn.setButtonText("Calculate");
	calculateBtn.addListener(this);


	//===========================Show result=======================================
	addAndMakeVisible(resultLabel);
	resultLabel.setFont(juce::Font(12.0f));
	resultLabel.setText("Transposed note is: ", juce::dontSendNotification);
	resultLabel.setColour(juce::Label::textColourId, juce::Colours::black);

	addAndMakeVisible(showResultLabel);
	showResultLabel.setFont(juce::Font(12.0f, juce::Font::bold));
	showResultLabel.setText("---", juce::dontSendNotification);
	showResultLabel.setColour(juce::Label::textColourId, juce::Colours::black);
	showResultLabel.setColour(juce::Label::outlineColourId, juce::Colours::grey);

	setSize(380, 150);
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	g.fillAll(juce::Colour(240, 240, 240));
}

//==============================================================================
void MainComponent::resized()
{
	noteLabel.setBounds(10, 10, getWidth() - 20, 30);
	inputNoteText.setBounds(240, 15, getWidth() - 255, 20);

	intervalLabel.setBounds(10, 40, getWidth() - 20, 30);
	inputIntervalText.setBounds(240, 45, getWidth() - 255, 20);

	calculateBtn.setBounds(127, 80, getWidth() - 255, 30);

	resultLabel.setBounds(10, 120, getWidth() - 20, 30);
	showResultLabel.setBounds(240, 125, getWidth() - 255, 20);
}

//==============================================================================
void MainComponent::buttonClicked(juce::Button*)
{
	showResultLabel.setText(calculateInterval(), juce::dontSendNotification);
}

//==============================================================================
juce::String MainComponent::calculateInterval()
{
	juce::String result;
	const char* table[12] = { "C", "C#", "D", "D#",
							  "E", "F", "F#", "G",
							  "G#", "A", "A#", "B" };

	juce::String inputStr = inputNoteText.getText().toUpperCase();
	int noteIndex = inputIntervalText.getText().getIntValue();

	for (int i = 0; i < 12; i++)
		if (!inputStr.containsWholeWord(table[i])) {
			result = "Could not find!";
		}
		else {
			while (noteIndex < 0)
				noteIndex += 12;
			while (noteIndex >= 12)
				noteIndex -= 12;

			for (int i = 0; i < 12; i++)
				if (inputStr.containsWholeWord(table[i]))
					noteIndex += i;
			if (noteIndex > 12)
				noteIndex -= 12;

			result = table[noteIndex];
			break;
		}

	return result;
}
