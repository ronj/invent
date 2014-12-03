#ifndef OPUS_CODEC_H
#define OPUS_CODEC_H

#include "audio_codec.h"

#include <memory>
#include <string>
#include <vector>

class IAudioInfo;
class IDataAccess;

class OpusCodec : public IAudioCodec
{
public:
	OpusCodec(std::unique_ptr<IDataAccess> aDataAccess);
	virtual ~OpusCodec();

	std::size_t decode(float* aSamples, std::size_t aSampleCount) const;
	std::size_t encode(const float* aSamples, std::size_t aSampleCount) const;

	const IAudioInfo& info() const;

	static std::vector<std::string> supportedExtensions();
	static std::vector<std::string> supportedMimeTypes();

private:
	class Impl;
	std::unique_ptr<Impl> iImpl;
};

#endif // !OPUS_CODEC_H
