#pragma once

#include <JuceHeader.h>

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    juce::String calcInterval();
    int calcPitchClasses(juce::String str);
    juce::String returnInterval(int interval);

private:
    //==============================================================================
    juce::Label titleLabel;
    juce::Label inputFirstLabel;
    juce::Label inputFirstText;

    juce::Label inputSecondLabel;
    juce::Label inputSecondText;

    juce::Label inervalLabel;
    juce::Label showResult;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
