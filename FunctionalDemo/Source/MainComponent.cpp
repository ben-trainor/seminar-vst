#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize(800, 533);
    
    
    //Tooltips
    addAndMakeVisible(inGain.t);
    inGain.setTooltipString("Volume boost on the front end");
    addAndMakeVisible(outGain.t);
    addAndMakeVisible(attack.t);
    addAndMakeVisible(release.t);
        
    // Slider declarations, for the main knobs
    inGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    inGain.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    inGainLabel.setText("IN", juce::NotificationType::dontSendNotification);
    inGainLabel.attachToComponent(&inGain, false);
    inGain.setLookAndFeel(&otherLookAndFeel);
    
    outGain.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    outGain.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    outGainLabel.setText("OUT", juce::NotificationType::dontSendNotification);
    outGainLabel.attachToComponent(&outGain, false);
    outGain.setLookAndFeel(&otherLookAndFeel);
    
    attack.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    attack.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    attackLabel.setText("ATTACK", juce::NotificationType::dontSendNotification);
    attackLabel.attachToComponent(&attack, false);
    attack.setLookAndFeel(&otherLookAndFeel);
    
    release.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    release.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    releaseLabel.setText("RELEASE", juce::NotificationType::dontSendNotification);
    releaseLabel.attachToComponent(&release, false);
    release.setLookAndFeel(&otherLookAndFeel);
    
    
    // Add them components to the screen
    addAndMakeVisible(inGain);
    addAndMakeVisible(outGain);
    addAndMakeVisible(attack);
    addAndMakeVisible(release);
    addAndMakeVisible(inGainLabel);
    addAndMakeVisible(outGainLabel);
    addAndMakeVisible(attackLabel);
    addAndMakeVisible(releaseLabel);
    addAndMakeVisible(ratio4);
    addAndMakeVisible(ratio8);
    addAndMakeVisible(ratio12);
    addAndMakeVisible(ratio20);
    
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::steelblue);
    g.setColour(juce::Colours::white);
        
//    g.drawRect(topLeft);
//    g.drawRect(topRight);
//    g.drawRect(bottomLeft);
//    g.drawRect(bottomRight);
    g.drawRect(topMiddle);
//    g.drawRect(buttonBox);
}

void MainComponent::resized()
{
    
    const float knobWidth = getWidth() / 4;
    const float knobScaleModifier = 0.9;
    const float meterWidth = getWidth() / 3;
    const float meterHeight = meterWidth * 0.8;
    const float border = getWidth() / 20;
    const float borderModifier = 1.5;
    const float buttonBoxBorder = getWidth() / 100;

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
    
        topMiddlePoint.setX(topMiddle.getX());
        topMiddlePoint.setY(topMiddle.getY());
    
    // Bottom row of functions
    
        // Knobs
        bottomLeft.setWidth(knobWidth * knobScaleModifier);
        bottomLeft.setHeight(bottomLeft.getWidth());
        bottomLeft.setPosition(0 + (border * borderModifier), getHeight() - border - bottomLeft.getHeight());
        bottomRight.setWidth(knobWidth * knobScaleModifier);
        bottomRight.setHeight(bottomRight.getWidth());
        bottomRight.setPosition(getWidth() - (border * borderModifier) - bottomRight.getWidth(), getHeight() - border - bottomRight.getHeight());
    
        // Buttons
        buttonBox.setWidth(meterWidth);
        buttonBox.setHeight(meterHeight);
        buttonBox.setPosition((getWidth() / 2) - (meterWidth / 2), getHeight() - border - meterHeight);
    
        ratio4.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
        ratio4.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio4.getHeight() / 2) - buttonBoxBorder);
        ratio8.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
        ratio8.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + (ratio8.getHeight() / 2) + buttonBoxBorder);
        ratio12.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
        ratio12.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio12.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio12.getHeight() / 2) - buttonBoxBorder);
        ratio20.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
        ratio20.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio20.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + (ratio20.getHeight() / 2) + buttonBoxBorder);
    
    
    
    inGain.setBounds(topLeft);
    outGain.setBounds(topRight);
    attack.setBounds(bottomLeft);
    release.setBounds(bottomRight);
    
    
}

//==============================================================================
