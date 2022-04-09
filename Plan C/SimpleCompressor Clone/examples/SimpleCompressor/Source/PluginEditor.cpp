/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleCompressorAudioProcessorEditor::SimpleCompressorAudioProcessorEditor (SimpleCompressorAudioProcessor& p, AudioProcessorValueTreeState& params)
    : AudioProcessorEditor (&p), processor (p), parameters (params),
    cv (processor.getGainReductionComputer()),
    threshold (Slider::RotaryVerticalDrag, Slider::TextBoxBelow),
    knee (Slider::RotaryVerticalDrag, Slider::TextBoxBelow),
    attack (Slider::RotaryVerticalDrag, Slider::TextBoxBelow),
    release (Slider::RotaryVerticalDrag, Slider::TextBoxBelow),
    ratio (Slider::RotaryVerticalDrag, Slider::TextBoxBelow),
    makeUp (Slider::RotaryVerticalDrag, Slider::TextBoxBelow)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800,533);

//    addAndMakeVisible (threshold);
//    thresholdAttachment.reset (new SliderAttachment (parameters, "threshold", threshold));
//    threshold.setTextValueSuffix (" dB");
//
//    addAndMakeVisible (knee);
//    kneeAttachment.reset (new SliderAttachment (parameters, "knee", knee));
//    knee.setTextValueSuffix (" dB");
//
//    addAndMakeVisible (attack);
//    attackAttachment.reset (new SliderAttachment (parameters, "attack", attack));
//    attack.setTextValueSuffix (" ms");
//
//    addAndMakeVisible (release);
//    releaseAttachment.reset (new SliderAttachment (parameters, "release", release));
//    release.setTextValueSuffix (" ms");
//
//    addAndMakeVisible (ratio);
//    ratioAttachment.reset (new SliderAttachment (parameters, "ratio", ratio));
//    ratio.setTextValueSuffix (" : 1");
//
//    addAndMakeVisible (makeUp);
//    makeUpAttachment.reset (new SliderAttachment (parameters, "makeUp", makeUp));
//    makeUp.setTextValueSuffix (" dB");
//
    addAndMakeVisible (cv);
    startTimer (50);
    
    // Slider declarations, for the main knobs
    inGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    inGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    inGainLabel.setText("THRESHOLD", juce::NotificationType::dontSendNotification);
    inGainLabel.attachToComponent(&inGainSlider, false);
    inGainSlider.setLookAndFeel(&otherLookAndFeel);
    inGainSlider.setBubbleMsg("How loud the signal must be before getting compressed");
    thresholdAttachment.reset (new SliderAttachment (parameters, "threshold", inGainSlider));
    
    outGainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    outGainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    outGainLabel.setText("OUT", juce::NotificationType::dontSendNotification);
    outGainLabel.attachToComponent(&outGainSlider, false);
    outGainSlider.setLookAndFeel(&otherLookAndFeel);
    outGainSlider.setBubbleMsg("Makeup lost gain after processing");
    makeUpAttachment.reset (new SliderAttachment (parameters, "makeUp", outGainSlider));
    
    attackSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    attackSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    attackLabel.setText("ATTACK", juce::NotificationType::dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, false);
    attackSlider.setLookAndFeel(&otherLookAndFeel);
    attackSlider.setBubbleMsg("How quickly compression acts");
    attackAttachment.reset (new SliderAttachment (parameters, "attack", attackSlider));
    
    releaseSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    releaseSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    releaseLabel.setText("RELEASE", juce::NotificationType::dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, false);
    releaseSlider.setLookAndFeel(&otherLookAndFeel);
    releaseSlider.setBubbleMsg("How long compression holds onto the signal");
    releaseAttachment.reset (new SliderAttachment (parameters, "release", releaseSlider));
    
    ratioSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    ratioSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    ratioLabel.setText("RATIO", juce::NotificationType::dontSendNotification);
    ratioLabel.attachToComponent(&ratioSlider, false);
    ratioSlider.setLookAndFeel(&otherLookAndFeel);
    ratioSlider.setBubbleMsg("How strongly the compressor reacts");
    ratioAttachment.reset (new SliderAttachment (parameters, "ratio", ratioSlider));
    
    
    
//    addAndMakeVisible(ratio4);
//    addAndMakeVisible(ratio8);
//    addAndMakeVisible(ratio12);
//    addAndMakeVisible(ratio20);
    
    addAndMakeVisible(inGainSlider);
    addAndMakeVisible(outGainSlider);
    addAndMakeVisible(attackSlider);
    addAndMakeVisible(releaseSlider);
    addAndMakeVisible(ratioSlider);
    
    addAndMakeVisible(inGainLabel);
    addAndMakeVisible(outGainLabel);
    addAndMakeVisible(attackLabel);
    addAndMakeVisible(releaseLabel);
    addAndMakeVisible(ratioLabel);
    
    addAndMakeVisible(inGainSlider.bubbleMsg);
    addAndMakeVisible(outGainSlider.bubbleMsg);
    addAndMakeVisible(attackSlider.bubbleMsg);
    addAndMakeVisible(releaseSlider.bubbleMsg);
    addAndMakeVisible(ratioSlider.bubbleMsg);
    
    
}

SimpleCompressorAudioProcessorEditor::~SimpleCompressorAudioProcessorEditor()
{
}

//==============================================================================
void SimpleCompressorAudioProcessorEditor::paint (Graphics& g)
{
//    auto bounds = getLocalBounds();

//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//
//    g.setColour (Colours::white);
//    g.setFont (20.0f);
//
//    g.drawFittedText ("SimpleCompressor", bounds.removeFromTop (25), Justification::centred, 1);
//
//    auto labelRow = bounds.removeFromBottom (12);
//
//    g.setFont (10.0f);
//    g.drawFittedText ("Threshold", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
//    labelRow.removeFromLeft (8);
//    g.drawFittedText ("Knee", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
//    labelRow.removeFromLeft (8);
//    g.drawFittedText ("Attack", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
//    labelRow.removeFromLeft (8);
//    g.drawFittedText ("Release", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
//    labelRow.removeFromLeft (8);
//    g.drawFittedText ("Ratio", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
//    labelRow.removeFromLeft (8);
//    g.drawFittedText ("MakeUp", labelRow.removeFromLeft (60), 12, Justification::centred, 1);
    
    g.fillAll(juce::Colours::steelblue);
    g.setColour(juce::Colours::white);
    
    g.drawRect(topMiddle);
    g.fillRect(topMiddle);
//    g.drawRect(buttonBox);

}

void SimpleCompressorAudioProcessorEditor::resized()
{
//    auto bounds = getLocalBounds();
//    bounds.removeFromTop (22);
//    bounds.removeFromBottom (12);
//
//    auto row = bounds.removeFromBottom (80);
//
//    threshold.setBounds (row.removeFromLeft (60));
//    row.removeFromLeft (8);
//    knee.setBounds (row.removeFromLeft (60));
//    row.removeFromLeft (8);
//    attack.setBounds (row.removeFromLeft (60));
//    row.removeFromLeft (8);
//    release.setBounds (row.removeFromLeft (60));
//    row.removeFromLeft (8);
//    ratio.setBounds (row.removeFromLeft (60));
//    row.removeFromLeft (8);
//    makeUp.setBounds (row.removeFromLeft (60));
//
    
    /* My code */
    
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
        buttonBox.setWidth(meterWidth / 1.5);
        buttonBox.setHeight(meterHeight / 1.5);
        buttonBox.setPosition((getWidth() / 2) - (meterWidth / 3), getHeight() - meterHeight / 1.01);
    
//        ratio4.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio4.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio4.getHeight() / 2) - buttonBoxBorder);
//        ratio8.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio8.setCentrePosition(buttonBox.getX() + (ratio4.getWidth() / 2) + buttonBoxBorder, buttonBox.getY() + (ratio8.getHeight() / 2) + buttonBoxBorder);
//        ratio12.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio12.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio12.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + buttonBox.getHeight() - (ratio12.getHeight() / 2) - buttonBoxBorder);
//        ratio20.setSize((buttonBox.getWidth() / 2) - buttonBoxBorder, (buttonBox.getHeight() / 2) - buttonBoxBorder);
//        ratio20.setCentrePosition(buttonBox.getX() + buttonBox.getWidth() - (ratio20.getWidth() / 2) - buttonBoxBorder, buttonBox.getY() + (ratio20.getHeight() / 2) + buttonBoxBorder);
    
        ratio.setBounds(buttonBox);
    
    // Tooltips
    inGainSlider.setBubblePosition(topLeft);
    outGainSlider.setBubblePosition(topRight);
    attackSlider.setBubblePosition(bottomLeft);
    releaseSlider.setBubblePosition(bottomRight);
    ratioSlider.setBubblePosition(buttonBox);
    
    
    inGainSlider.setBounds(topLeft);
    outGainSlider.setBounds(topRight);
    attackSlider.setBounds(bottomLeft);
    releaseSlider.setBounds(bottomRight);
    ratioSlider.setBounds(buttonBox);
    
    cv.setBounds (topMiddle);
    
    
}


void SimpleCompressorAudioProcessorEditor::timerCallback()
{
    if (processor.characteristicChanged.get())
    {
        processor.characteristicChanged = false;
        cv.updateCharacteristic();
    }
    
    cv.repaint();
}
