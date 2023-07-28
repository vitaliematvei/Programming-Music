/*
  ==============================================================================

	This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor(GainAudioProcessor& p)
	: AudioProcessorEditor(&p), audioProcessor(p)
{
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(400, 100);

	addAndMakeVisible(gainVolume);
	gainVolume.setSliderStyle(juce::Slider::LinearHorizontal);
	gainVolume.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
	gainVolume.setRange(-48.0, 0.0, 0.25);
	gainVolume.setPopupDisplayEnabled(true, false, this);
	gainVolume.setTextValueSuffix(" Volume");
	gainVolume.setValue(-1.0);
	gainVolume.addListener(this);
}

GainAudioProcessorEditor::~GainAudioProcessorEditor() 
{
}

//==============================================================================
void GainAudioProcessorEditor::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void GainAudioProcessorEditor::resized()
{
	gainVolume.setBounds(getLocalBounds());
}

void GainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
	if (slider == &gainVolume)
	{
		audioProcessor.audioVol = pow(10, gainVolume.getValue() / 20);
	}
}
