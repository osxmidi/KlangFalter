KlangFalter
===========
There are basically 2 config options.

1: Copy the contents of the JUCE6 modules folder to the plugin/JuceLibraryCode/modules folder (for making the default Vst3 version)

or

2: Reconfigure using Projucer.

Some files may then need to be edited
 
For Vst3, edit plugin/JuceLibraryCode/AppConfig.h 
 
and check that the below is entered
 
```
#ifndef    JUCE_VST3_CAN_REPLACE_VST2
#define JUCE_VST3_CAN_REPLACE_VST2 0
#endif 

```

To make with no Webkit, see the Webkit folder for manual config or choose the juce_gui_extra module in the Projucer and set 
 JUCE_WEB_BROWSER to Disabled.
 
Some libraries need to be installed

sudo apt-get -y install webkit2gtk-4.0 git pkg-config libfreetype6-dev libx11-dev libxinerama-dev libxrandr-dev libxcursor-dev mesa-common-dev libasound2-dev freeglut3-dev libxcomposite-dev libcurl4-gnutls-dev

To make the default Vst3 version, cd into the ~/JUCE6/unzipped KlangFalter master folder/plugin/Builds/Linux folder

make CONFIG=Release

vst3 is installed into ~/.vst3

------------

KlangFalter is a convolution audio plugin, e.g. for usage as convolution reverb.

I started its development a couple of time ago because I couldn't find a convolution reverb plugin which suited my needs - and because I was curious about audio DSP programming. ;-)

## Features: ##

- Zero-latency
- Easy user interface
- Support for true stereo impulse responses
- Simple 2-band EQ (low cut/shelf and high cut/shelf)
- Easy modifiable envelope for the impulse response
- Basically no limit on impulse response length - as long as your computer can handle it...
- Intuitive and flexible loading of impulse response files

![Screenshot](https://raw.github.com/HiFi-LoFi/KlangFalter/master/Screenshot.png)


## Getting KlangFalter: ##

Please check the [Binary](https://github.com/HiFi-LoFi/KlangFalter/tree/master/Binary) folder.
For installation, just download the according .zip file and extract it in your plug-in folder.

At the moment, I only build Audio Unit plugins for Mac. However, an LV2 version for Linux can be found
in the really great [distrho](http://distrho.sourceforge.net) distrho project.

## Linux Make

Linux make instructions

Some libraries need to be installed

sudo apt-get -y install webkit2gtk-4.0 git pkg-config libfreetype6-dev libx11-dev libxinerama-dev libxrandr-dev libxcursor-dev mesa-common-dev libasound2-dev freeglut3-dev libxcomposite-dev libcurl4-gnutls-dev

Install JUCE into ~/JUCE

Enable GPL mode

Edit ~/JUCE/extras/Projucer/JuceLibraryCode/AppConfig.h

and change #define JUCER_ENABLE_GPL_MODE to #define JUCER_ENABLE_GPL_MODE 1

Place the unzipped KlangFalter-master folder into the ~/JUCE folder

Place the vst2.4 sdk's pluginterfaces folder into ~/JUCE/modules/juce_audio_plugin_client/VST/

cd into ~/JUCE/Unzipped KlangFalter-master folder/Builds/Linux

make CONFIG=Release

Binaries are produced in the ~/JUCE/Unzipped KlangFalter-master folder/Builds/Linux/build folder

------------

To make without webkit dependencies

use Makefile-nowebkit (rename Makefile-nowebkit to Makefile and then make CONFIG=Release)

Some edits need to be made in 2 files

--------

juce_gui_extra.h in

/JUCE/modules/juce_gui_extra/

change

#ifndef JUCE_WEB_BROWSER

#define JUCE_WEB_BROWSER 1

#endif

to

#ifndef JUCE_WEB_BROWSER

// #define JUCE_WEB_BROWSER 1

#endif

--------

juce_ApplicationBase.cpp in

/JUCE/modules/juce_events/messages/

change

#if JUCE_LINUX && JUCE_MODULE_AVAILABLE_juce_gui_extra && (! defined(JUCE_WEB_BROWSER) || JUCE_WEB_BROWSER)

to

#if JUCE_LINUX && JUCE_MODULE_AVAILABLE_juce_gui_extra && JUCE_WEB_BROWSER

(there are 2 occurrences of it that need to be changed in the juce_ApplicationBase.cpp file)

------------

## Plugin Tutorial: ##

To use the KlangFalter plugin, click on "no file loaded" to load a IR file.

## Very Short Tutorial: ##

#### Loading impulse responses ####
- Click on the "Settings" button to adjust the folder which contains your impulse response files.
- Click on "Show Browser" and select some impulse response files.
- KlangFalter tries to find matching impulse response files automatically by searching for matching file names (e.g. left/right and true stereo).
- You can load impulse response files for specific channel connections by clicking on the file name beneath the wave form display of the according tab.  
- You can clear the impulse response of a specific channel connection by clicking on the "X" button of the according tab.

KlangFalter doesn't come with any impulse respones, but you can find many free and good impulse response collections on the web. Any file format supported by JUCE should work (currently at least .wav, .mp3, .aiff, .ogg and a couple more).

#### Mixing dry and wet signal ####
- *Wet/Dry*: Adjustment of the wet and dry signal.
- *Autogain*: "Normalizes" the loaded impulse responses in order to achieve a consistent level.
- *Stereo Width*: Adjusts the - guess what - stereo width.
- Click on the label on top of the right level display to switch the according level measurement between "out" and "wet" mode.

#### Modifying the impulse response ####
- *Gap*: Additional gap at the begin of the impulse response ("pre-delay").
- *Begin*: Begin of the impulse response.
- *End*: End of the impulse response
- *Stretch*: Stretches the impulse response.
- *Attack Length & Shape*: Modifies the front (attack) of the impulse response.
- *Decay Shape*: Modifies the decay of the impulse response
- *Reverse*: Reverts the impulse response for spacy effects.
- Click on the timeline at the bottom of the waveform display to switch time measurement between time and beats-per-minute (useful e.g. for timing reverbs to the music).

#### EQ ####
- Click on the header of the low resp. high EQ to switch between cut and shelf filter.
- *Freq*: Adjusts the frequency of the according EQ.
- *Gain*: EQ gain (only available if working as shelf filter).


## Technical Stuff: ##

- Open source ([GPL](http://www.gnu.org/licenses) license)
- SSE optimized algorithm
- Multithreaded convolution engine
- Written in C++
- Based on the great [JUCE](http://www.juce.com) framework, updated for JUCE v5.4.4
