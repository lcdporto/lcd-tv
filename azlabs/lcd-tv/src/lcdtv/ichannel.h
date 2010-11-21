#ifndef LCDTV_ICHANNEL_H
#define LCDTV_ICHANNEL_H

#include <string>
#include "ofImage.h"

//
// lcdtv::ichannel
//
// Base interface for a channel.
//

namespace lcdtv {

    class ichannel {

        public:

            ichannel (const std::string & channel_name, const std::string &id_image_path):
                m_ChannelName (channel_name),
                m_IDImage()
            {
                m_IDImage.loadImage (id_image_path);
            }

            virtual ~ichannel() {}

            virtual const std::string & getChannelName()
            {
                return m_ChannelName;
            }

            virtual void drawIDImage (unsigned int x, unsigned int y, unsigned int width, unsigned int height)
            {
                ofEnableAlphaBlending();
                m_IDImage.draw (x, y, width, height);
                ofDisableAlphaBlending();
            }

            // (Re)start the channel video source
            virtual void play() = 0;

            // Stop playing the channel video source
            virtual void stop() = 0;

            // Update the channel video source
            virtual void update() = 0;

            // Draw the channel video source
            virtual void draw (unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;

        protected:

            std::string m_ChannelName;
            ofImage m_IDImage;
    };

} // namespace lcdtv

#endif // LCDTV_ICHANNEL_H
