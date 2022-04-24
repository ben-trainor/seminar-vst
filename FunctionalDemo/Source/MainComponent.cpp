#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // set size of plugin window using 1.5:1 ratio
    setSize(800, 533);
    
    
    // Slider formatting, for the main knobs
    inGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag); // click and drag upwards to rotate clockwise, vice versa
    inGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    inGainLabel.setText("IN", juce::NotificationType::dontSendNotification);
    inGainLabel.attachToComponent(&inGainSlider, false);
    inGainSlider.setLookAndFeel(&otherLookAndFeel); // change draw style to custom LookAndFeel class
    inGainSlider.setBubbleMsg("Boost the signal volume before it gets processed"); // tooltip message declaration
    addAndMakeVisible(inGainSlider.bubbleMsg); // must add the message to the screen
    
    outGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    outGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    outGainLabel.setText("OUT", juce::NotificationType::dontSendNotification);
    outGainLabel.attachToComponent(&outGainSlider, false);
    outGainSlider.setLookAndFeel(&otherLookAndFeel);
    outGainSlider.setBubbleMsg("Boost the signal volume before it gets processed");
    addAndMakeVisible(outGainSlider.bubbleMsg);
    
    attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    attackLabel.setText("ATTACK", juce::NotificationType::dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, false);
    attackSlider.setLookAndFeel(&otherLookAndFeel);
    attackSlider.setBubbleMsg("Boost the signal volume before it gets processed");
    addAndMakeVisible(attackSlider.bubbleMsg);
    
    releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    releaseLabel.setText("RELEASE", juce::NotificationType::dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, false);
    releaseSlider.setLookAndFeel(&otherLookAndFeel);
    releaseSlider.setBubbleMsg("Boost the signal volume before it gets processed");
    addAndMakeVisible(releaseSlider.bubbleMsg);
    
    
    // Add the components to the screen
    addAndMakeVisible(inGainSlider);
    addAndMakeVisible(outGainSlider);
    addAndMakeVisible(attackSlider);
    addAndMakeVisible(releaseSlider);
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
    juce::Font theFont("VCR OSD Mono", "regular", 20.0f);
    g.setFont(theFont);
    
    // Rectangles for reference
//    g.drawRect(topLeft);
//    g.drawRect(topRight);
//    g.drawRect(bottomLeft);
//    g.drawRect(bottomRight);
//    g.drawRect(buttonBox);
    g.drawRect(topMiddle); // border around graph
}

void MainComponent::resized()
{
    
    // Dimensions for drawing GUI
    // Proportionally based on width of GUI for easy modification
    const float knobWidth = getWidth() / 4;
    const float knobScaleModifier = 0.9;
    const float meterWidth = getWidth() / 3;
    const float meterHeight = meterWidth * 0.8;
    const float border = getWidth() / 20;
    const float borderModifier = 1.5;
//    const float buttonBoxBorder = getWidth() / 100;

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
    
        // OLD BUTTONS
//        ratio4.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio4.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio4.getHeight() / 2) - buttonBoxBorder);
//        ratio8.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio8.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + (ratio8.getHeight() / 2) + buttonBoxBorder);
//        ratio12.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio12.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio12.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio12.getHeight() / 2) - buttonBoxBorder);
//        ratio20.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio20.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio20.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + (ratio20.getHeight() / 2) + buttonBoxBorder);
    
    
    // Align tooltips to corresponding knobs
    inGainSlider.setBubblePosition(topLeft);
    outGainSlider.setBubblePosition(topRight);
    attackSlider.setBubblePosition(bottomLeft);
    releaseSlider.setBubblePosition(bottomRight);
    
    inGainSlider.setBounds(topLeft);
    outGainSlider.setBounds(topRight);
    attackSlider.setBounds(bottomLeft);
    releaseSlider.setBounds(bottomRight);
    
    
}


