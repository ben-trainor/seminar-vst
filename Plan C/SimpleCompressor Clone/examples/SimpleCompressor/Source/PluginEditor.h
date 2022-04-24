/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "../../thirdparty/CompressorVisualizer.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;



//==============================================================================
/* Class built by Ben Trainor */
class OtherLookAndFeel : public juce::LookAndFeel_V4 {
    public:
    
    
        // Taken from JUCE tutorials
        void drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &) override {
            
            auto radius = (float) juce::jmin (width / 2.5, height / 2.5) - 4.0f;
            auto centreX = (float) x + (float) width  * 0.5f;
            auto centreY = (float) y + (float) height * 0.5f;
            auto rx = centreX - radius;
            auto ry = centreY - radius;
            auto rw = radius * 2.0f;
            auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
            
            // Color options chosen by me
            // fill
            g.setColour (juce::Colours::white);
            g.fillEllipse (rx, ry, rw, rw);
     
            // outline
            g.setColour (juce::Colours::darkgrey);
            g.drawEllipse (rx, ry, rw, rw, 3.0f);
                        
            // pointer
            juce::Path p;
            auto pointerLength = radius * 0.33f;
            auto pointerThickness = 2.0f;
            p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
            p.applyTransform (juce::AffineTransform::rotation (angle).translated (centreX, centreY));
            g.setColour (juce::Colours::black);
            g.fillPath (p);
            
        }
    
};


//==============================================================================
/* Class built by Ben Trainor */
class TooltipSlider : public juce::Slider {

    public:

        juce::AttributedString bubbleMsgString;
        juce::BubbleMessageComponent bubbleMsg;
        juce::Rectangle<int> bubbleRectangle;

        // defining the text within the slider's bubble and a rectangle around the slider
        // remember to do these two in the main CPP file when creating a component!
        void setBubbleMsg(juce::String msg) {
            bubbleMsgString.clear();
            bubbleMsgString.append(msg, juce::Colours::white);
        }
        void setBubblePosition(juce::Rectangle<int> r) {
            bubbleRectangle.setBounds(r.getX(), r.getY(), r.getWidth(), r.getHeight());
        }

        // on right click, display the bubble hint
        void mouseDown(const juce::MouseEvent &e) override {

            juce::ModifierKeys modifiers = juce::ModifierKeys::getCurrentModifiersRealtime();

            // check the modkeys
            if (modifiers.isPopupMenu()) {
                bubbleMsg.showAt(bubbleRectangle, juce::AttributedString(bubbleMsgString), 2000);
            }
            else {
                juce::Slider::mouseDown(e); // do the normal click function
            }

        }

};

//==============================================================================

class SimpleCompressorAudioProcessorEditor  : public AudioProcessorEditor, private Timer
{
public:
    SimpleCompressorAudioProcessorEditor (SimpleCompressorAudioProcessor&, AudioProcessorValueTreeState&);
    ~SimpleCompressorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void timerCallback() override;

private:
    
    // SimpleCompressor
    //==============================================================================
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it. (from SimpleCompressor)
    SimpleCompressorAudioProcessor& processor;
    AudioProcessorValueTreeState& parameters;

    // Graph instance
    CompressorVisualizer cv;
    
    // Ben Trainor's sliders
    // Have to declare these before pointers
    TooltipSlider inGainSlider, outGainSlider, attackSlider, releaseSlider, ratioSlider;
    juce::Label inGainLabel, outGainLabel, attackLabel, releaseLabel, ratioLabel;

    // Unused SimpleCompressor slider
    Slider threshold, knee, attack, release, ratio, makeUp;
    std::unique_ptr<SliderAttachment> thresholdAttachment, kneeAttachment, attackAttachment,
        releaseAttachment, ratioAttachment, makeUpAttachment;
    
    // Ben Trainor code
    //==============================================================================
    OtherLookAndFeel otherLookAndFeel;
    
    // Rectangles for use with the GUI code
    juce::Rectangle<int> topLeft, topRight, bottomLeft, bottomRight, topMiddle;
    juce::Rectangle<int> buttonBox; // Unused
    
    juce::Point<int> topMiddlePoint;
    
    // Unused
    juce::TextButton ratio4 {"4:1"};
    juce::TextButton ratio8 {"8:1"};
    juce::TextButton ratio12 {"12:1"};
    juce::TextButton ratio20 {"20:1"};

    juce::BubbleMessageComponent bubbleMsg;

    juce::MouseListener rightClickListener;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleCompressorAudioProcessorEditor)
};
