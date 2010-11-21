#include "folder_channel.h"

lcdtv::folder_channel::folder_channel (const std::string &channel_name,
                                      const std::string &id_image_path,
                                      const std::string &folder_path):
    ichannel (channel_name, id_image_path),
    m_FolderList(),
    m_ChannelPlayer(),
    m_TextRenderer(),
    m_NumPrograms (0),
    m_CurrentProgram (0)
{
    m_FolderList.allowExt ("mp4");
    m_FolderList.allowExt ("mov");
    m_FolderList.allowExt ("flv");
    m_FolderList.allowExt ("avi");
    m_FolderList.allowExt ("ogm");
    m_FolderList.allowExt ("ogg");

    m_NumPrograms = m_FolderList.listDir (folder_path);

    m_ChannelPlayer.setLoopState (OF_LOOP_NONE);

    if (m_NumPrograms != 0) {
        m_ChannelPlayer.loadMovie (m_FolderList.getPath (m_CurrentProgram));
    }

    m_TextRenderer.loadFont ("font/neutrond.ttf", 32);
}


lcdtv::folder_channel::~folder_channel()
{

}

void
lcdtv::folder_channel::play()
{
    if (m_NumPrograms != 0) {
        m_ChannelPlayer.play();
    }
}

void
lcdtv::folder_channel::stop()
{
    if (m_NumPrograms != 0) {
        m_ChannelPlayer.stop();
    }
}

void
lcdtv::folder_channel::update()
{
    // Check if we have any programs
    if (m_NumPrograms == 0) {
        return;
    }

    // Check if we need to change program
    if (m_ChannelPlayer.getIsMovieDone()) {
        m_CurrentProgram++;
        if (m_CurrentProgram >= m_NumPrograms) {
            m_CurrentProgram = 0;
        }
        m_ChannelPlayer.stop();
        m_ChannelPlayer.loadMovie (m_FolderList.getPath (m_CurrentProgram));
        m_ChannelPlayer.play();
    }

    // Update current program
    m_ChannelPlayer.update();
}

void
lcdtv::folder_channel::draw (unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    ofBackground (0, 0, 0);
    ofSetColor (255, 255, 255);

    std::string program_name;
    if (m_NumPrograms != 0) {
        // Try and be smart about the movie scaling
        float movie_aspect = (float) m_ChannelPlayer.getWidth() / (float) m_ChannelPlayer.getHeight();
        float fit_height = width / movie_aspect;
        float height_offset = (height - fit_height) / 2.0;

        m_ChannelPlayer.draw (x, height_offset, width, fit_height);
        program_name = m_FolderList.getName (m_CurrentProgram);
    }
    else {
        program_name = "Channel has no programs\nAdd some videos to channel folder";
    }

    m_IDImage.draw (x + 18, y + 18, 32, 32);
    m_TextRenderer.drawString (m_ChannelName, x + 100, y + 50);
    m_TextRenderer.drawString (program_name, x + 18, height - 100);
}
