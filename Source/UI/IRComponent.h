/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  13 Oct 2012 12:01:59pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_IRCOMPONENT_IRCOMPONENT_F0EF5034__
#define __JUCER_HEADER_IRCOMPONENT_IRCOMPONENT_F0EF5034__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"

#include "WaveformComponent.h"
#include "../IRAgent.h"
#include "../IRManager.h"
#include "../PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class IRComponent  : public Component,
                     public ChangeListener,
                     public ButtonListener,
                     public ComboBoxListener
{
public:
    //==============================================================================
    IRComponent ();
    ~IRComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void init(IRManager* irManager, size_t inputChannel, size_t outputChannel);
    void irChanged();

    virtual void changeListenerCallback(ChangeBroadcaster* source);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    IRAgent* _irAgent;
    IRManager* _irManager;
    //[/UserVariables]

    //==============================================================================
    WaveformComponent* _waveformComponent;
    TextButton* _loadButton;
    TextButton* _clearButton;
    ComboBox* _channelComboBox;
    Label* _channelHeaderLabel;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    IRComponent (const IRComponent&);
    const IRComponent& operator= (const IRComponent&);
};


#endif   // __JUCER_HEADER_IRCOMPONENT_IRCOMPONENT_F0EF5034__