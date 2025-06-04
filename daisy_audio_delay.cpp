#include "daisy_pod.h"
#include "daisysp.h"

using namespace daisy;
using namespace daisysp;

#define MAX_DELAY_TIME (0.050f)
#define DELAY_BUF_SAMPLES ((size_t)(MAX_DELAY_TIME * 48000.0f))

DaisyPod hw;

DelayLine<float, DELAY_BUF_SAMPLES> del;

void AudioCallback(AudioHandle::InputBuffer in, AudioHandle::OutputBuffer out, size_t size)
{
	hw.ProcessAllControls();

	// set delay time, rounding to nearest sample
	float delay_setting = hw.knob1.Value();
	if (delay_setting < 0.001f)
	{
		del.SetDelay((size_t)1); // minimum delay of 1 sample
	}
	else
	{
		del.SetDelay((size_t)(delay_setting*DELAY_BUF_SAMPLES + 0.5f));
	}

	for (size_t i = 0; i < size; i++)
	{
		float sample = in[0][i];
		del.Write(sample);
		out[0][i] = del.Read();
		out[1][i] = del.Read();
	}
}

int main(void)
{
	hw.Init();
	hw.SetAudioBlockSize(4); // number of samples handled per callback
	hw.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
	hw.StartAdc();
	hw.StartAudio(AudioCallback);
	while(1) {}
}
