#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider inGain;
    juce::Label inGainLabel;
    juce::Slider outGain;
    juce::Label outGainLabel;
    juce::Slider attack;
    juce::Label attackLabel;
    juce::Slider release;
    juce::Label releaseLabel;
    
    juce::Rectangle<int> topLeft;
    juce::Rectangle<int> topRight;
    juce::Rectangle<int> bottomLeft;
    juce::Rectangle<int> bottomRight;
    juce::Rectangle<int> topMiddle;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
