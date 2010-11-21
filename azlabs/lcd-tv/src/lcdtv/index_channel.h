#ifndef LCDTV_INDEX_CHANNEL_H
#define LCDTV_INDEX_CHANNEL_H

#include "ichannel.h"

//
// lcdtv::index_channel displays a list of channels
//

namespace lcdtv {

    class index_channel : public ichannel {

        public:

            index_channel (const std::string & channel_name,
                           const std::string & channel_id_image_path,
                           const std::string & index_title,
                           const std::vector<ichannel *> * p_channels);

            ~index_channel ();

            void play();

            void stop();

            void update();

            void draw (unsigned int x, unsigned int y, unsigned int width, unsigned int height);

        private:

            ofTrueTypeFont m_ChannelFontRenderer;
            ofTrueTypeFont m_TitleFontRenderer;
            std::string m_TitleString;
            const std::vector<ichannel *> *m_pChannels;
    };

}

#endif // LCDTV_INDEX_CHANNEL_H
