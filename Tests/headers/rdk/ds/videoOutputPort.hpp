#pragma once

#include "videoOutputPortType.hpp"
#include "videoResolution.hpp"
#include "audioOutputPort.hpp"

namespace device {

class VideoOutputPortImpl {
public:
    virtual ~VideoOutputPortImpl() = default;

    virtual const VideoOutputPortType& getType() const = 0;
    virtual const std::string& getName() const = 0;
    virtual const VideoResolution& getDefaultResolution() const = 0;
    virtual int getHDCPProtocol() = 0;
    virtual int getHDCPReceiverProtocol() = 0;
    virtual int getHDCPCurrentProtocol() = 0;
    virtual int getHDCPStatus() = 0;
    virtual AudioOutputPort &getAudioOutputPort() const = 0;
    virtual bool isDisplayConnected() = 0;
    virtual bool isContentProtected() = 0;
};

class VideoOutputPort {
public:
    VideoOutputPortImpl* impl;

    const VideoOutputPortType& getType() const
    {
        return impl->getType();
    }

    const std::string& getName() const
    {
        return impl->getName();
    }

    const VideoResolution& getDefaultResolution() const
    {
        return impl->getDefaultResolution();
    }

    int getHDCPProtocol()
    {
        return impl->getHDCPProtocol();
    }

    int getHDCPReceiverProtocol()
    {
        return impl->getHDCPReceiverProtocol();
    }

    int getHDCPCurrentProtocol ()
    {
        return impl->getHDCPCurrentProtocol();
    }

    int getHDCPStatus()
    {
        return impl->getHDCPStatus();
    }

    AudioOutputPort &getAudioOutputPort()
    {
        return impl->getAudioOutputPort();
    }

    bool isDisplayConnected()
    {
        return impl->isDisplayConnected();
    }

    bool isContentProtected()
    {
        return impl->isContentProtected();
    }

};

}