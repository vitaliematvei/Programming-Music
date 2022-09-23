#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::Component,
	public juce::Button::Listener
{
public:
	//==============================================================================
	MainComponent();

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

	void buttonClicked(juce::Button*) override;
	juce::String calculateInterval();

private:
	//==============================================================================
	juce::Label noteLabel;
	juce::Label inputNoteLabel;
	juce::Label inputNoteText;

	juce::Label intervalLabel;
	juce::Label inputIntervalLabel;
	juce::Label inputIntervalText;

	juce::TextButton calculateBtn;

	juce::Label resultLabel;
	juce::Label showResultLabel;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
