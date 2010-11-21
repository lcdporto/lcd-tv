#ifndef LCDTV_CHANNEL_H
#define LCDTV_CHANNEL_H

#include "ichannel.h"
#include "ofxDirList.h"
#include "ofVideoPlayer.h"

//
// lcdtv::folder_channel
//
// Creates a video channel from a folder of video files
//

namespace lcdtv {

    class folder_channel : public ichannel {

        public:

            folder_channel (const std::string &channel_name, const std::string &id_image_path, const std::string &folder_path);

            ~folder_channel();

            void play();

            void stop();

            void update();

            void draw (unsigned int x, unsigned int y, unsigned int width, unsigned int height);

        private:

            ofxDirList m_FolderList;
            ofVideoPlayer m_ChannelPlayer;
            ofTrueTypeFont m_TextRenderer;
            unsigned int m_NumPrograms;
            unsigned int m_CurrentProgram;
    };

} // namespace lcdtv

#endif // LCDTV_CHANNEL_H
