#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::Component
{
public:
	//==============================================================================
	MainComponent();

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

private:
	//==============================================================================
	juce::Label noteLabel;
	juce::Label inputNoteLabel;
	juce::Label inputNoteText;

	juce::Label intervalLabel;
	juce::Label inputIntervalLabel;
	juce::Label inputIntervalText;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
