#ifndef SAMPLERATE_CONTROL_H
#define SAMPLERATE_CONTROL_H

#include <vector>

class SamplerateObserver;

class SamplerateControl
{
public:
  explicit SamplerateControl(float aSamplerate);

  void setSamplerate(float aSamplerate);
  float getSamplerate() const;

  void addSamplerateObserver(SamplerateObserver& aObserver);
  void removeSamplerateObserver(SamplerateObserver& aObserver);

private:
  void notifySamplerateObservers(float aNewRate, float aOldRate);

private:
  SamplerateControl(const SamplerateControl&) = delete;
  SamplerateControl operator=(const SamplerateControl&) = delete;

private:
  float                            iSamplerate;
  std::vector<SamplerateObserver*> iObservers;
};

#endif // SAMPLERATE_CONTROL_H
