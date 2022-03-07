#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize(800, 533);
    
        
    // Slider declarations, for the main knobs
    inGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    inGain.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    inGainLabel.setText("inGainLabel", juce::NotificationType::dontSendNotification);
    inGainLabel.attachToComponent(&inGain, false);
    
    outGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    outGain.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    outGainLabel.setText("outGainLabel", juce::NotificationType::dontSendNotification);
    outGainLabel.attachToComponent(&outGain, false);
    
    attack.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    attack.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    attackLabel.setText("attackLabel", juce::NotificationType::dontSendNotification);
    attackLabel.attachToComponent(&attack, false);
    
    release.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    release.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    releaseLabel.setText("releaseLabel", juce::NotificationType::dontSendNotification);
    releaseLabel.attachToComponent(&release, false);
    
    
    // Add them components to the screen
    addAndMakeVisible(inGain);
    addAndMakeVisible(outGain);
    addAndMakeVisible(attack);
    addAndMakeVisible(release);
    addAndMakeVisible(inGainLabel);
    addAndMakeVisible(outGainLabel);
    addAndMakeVisible(attackLabel);
    addAndMakeVisible(releaseLabel);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::steelblue);
    g.setColour(juce::Colours::white);
        
    g.drawRect(topLeft);
    g.drawRect(topRight);
    g.drawRect(bottomLeft);
    g.drawRect(bottomRight);
    g.drawRect(topMiddle);
}

void MainComponent::resized()
{
    
    const float knobWidth = getWidth() / 4;
    const float knobScaleModifier = 0.9;
    const float meterWidth = getWidth() / 3;
    const float meterHeight = meterWidth * 0.8;
    const float border = getWidth() / 20;
    const float borderModifier = 1.5;

    // Top row of functions
    
        // Knobs
        topLeft.setWidth(knobWidth);
        topLeft.setHeight(knobWidth);
        topLeft.setPosition(0 + border, 0 + border);
        topRight.setWidth(knobWidth);
        topRight.setHeight(knobWidth);
        topRight.setPosition(getWidth() - border - knobWidth, 0 + border);
    
        // Meter
        topMiddle.setWidth(meterWidth);
        topMiddle.setHeight(meterHeight);
        topMiddle.setPosition((getWidth() / 2) - (meterWidth / 2), 0 + border);
    
    // Bottom row of functions
    
        // Knobs
        bottomLeft.setWidth(knobWidth * knobScaleModifier);
        bottomLeft.setHeight(bottomLeft.getWidth());
        bottomLeft.setPosition(0 + (border * borderModifier), getHeight() - border - bottomLeft.getHeight());
        bottomRight.setWidth(knobWidth * knobScaleModifier);
        bottomRight.setHeight(bottomRight.getWidth());
        bottomRight.setPosition(getWidth() - (border * borderModifier) - bottomRight.getWidth(), getHeight() - border - bottomRight.getHeight());
    
    
    
    inGain.setBounds(topLeft);
    outGain.setBounds(topRight);
    attack.setBounds(bottomLeft);
    release.setBounds(bottomRight);
    
    
}
