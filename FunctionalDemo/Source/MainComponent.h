#pragma once

#include <JuceHeader.h>


//==============================================================================
class OtherLookAndFeel : public juce::LookAndFeel_V4 {
    public:
    
    
        void drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &) override {
            
            auto radius = (float) juce::jmin (width / 2.5, height / 2.5) - 4.0f;
            auto centreX = (float) x + (float) width  * 0.5f;
            auto centreY = (float) y + (float) height * 0.5f;
            auto rx = centreX - radius;
            auto ry = centreY - radius;
            auto rw = radius * 2.0f;
            auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
            
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

//            std::cout << "Hello, world!";

            juce::ModifierKeys modifiers = juce::ModifierKeys::getCurrentModifiersRealtime();

            // check the modkeys
            if (modifiers.isPopupMenu()) {
//                std::cout << "Right clicked!";
                bubbleMsg.showAt(bubbleRectangle, juce::AttributedString(bubbleMsgString), 2000);
            }
            else {
                juce::Slider::mouseDown(e); // do the normal click function
            }

        }

};


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public juce::Component
{
    public:
        //==============================================================================
        MainComponent();
        ~MainComponent() override;

        //==============================================================================
        void paint (juce::Graphics&) override;
        void resized() override;
    
    private:
        
        OtherLookAndFeel otherLookAndFeel;
        
        TooltipSlider inGain;
        juce::Label inGainLabel;
        TooltipSlider outGain;
        juce::Label outGainLabel;
        TooltipSlider attack;
        juce::Label attackLabel;
        TooltipSlider release;
        juce::Label releaseLabel;
        
        juce::Rectangle<int> topLeft;
        juce::Rectangle<int> topRight;
        juce::Rectangle<int> bottomLeft;
        juce::Rectangle<int> bottomRight;
        juce::Rectangle<int> topMiddle;
        juce::Rectangle<int> buttonBox; // Rectangle to hold all the ratio buttons
        
        juce::Point<int> topMiddlePoint;
        
        juce::TextButton ratio4 {"4:1"};
        juce::TextButton ratio8 {"8:1"};
        juce::TextButton ratio12 {"12:1"};
        juce::TextButton ratio20 {"20:1"};
    
        juce::BubbleMessageComponent bubbleMsg;
    
        juce::MouseListener rightClickListener;
    

        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    
};

