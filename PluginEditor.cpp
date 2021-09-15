/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RomplerAudioProcessorEditor::RomplerAudioProcessorEditor (RomplerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setLookAndFeel(&pulsarFeel);
    mWaveThumbnail = std::make_unique<WaveThumbnail>(p);
    addAndMakeVisible (mWaveThumbnail.get());

    mADSR = std::make_unique<ADSRComponent>(p);
    addAndMakeVisible (mADSR.get());
    mADSR->setAlwaysOnTop(true);

    rompMenu = std::make_unique<RompMenu>(p);
    addAndMakeVisible(rompMenu.get());

    startTimerHz (30);
    
    setSize (600, 400);
}

RomplerAudioProcessorEditor::~RomplerAudioProcessorEditor()
{
    stopTimer();
}

//==============================================================================
void RomplerAudioProcessorEditor::paint (Graphics& g)
{
    auto color = Colour{ 0.001f, 0.f, 0.0005f, 1.f };
    g.fillAll(color);
}

void RomplerAudioProcessorEditor::resized()
{
    rompMenu->setBoundsRelative(0.f, 0.f, 1.0f, 0.1f);
    mWaveThumbnail->setBoundsRelative (0.01f, 0.f, 0.98f, 1.f);
    mADSR->setBoundsRelative (0.0f, 0.75f, 1.0f, 0.25f);
}

void RomplerAudioProcessorEditor::timerCallback()
{
    repaint();
}



