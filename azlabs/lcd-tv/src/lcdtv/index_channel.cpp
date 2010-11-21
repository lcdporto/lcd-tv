#include "index_channel.h"

 lcdtv::index_channel::index_channel (const std::string & channel_name,
                           const std::string & channel_id_image_path,
                           const std::string & index_title,
                           const std::vector<ichannel *> * p_channels):
                               ichannel (channel_name, channel_id_image_path),
                               m_ChannelFontRenderer(),
                               m_TitleFontRenderer(),
                               m_TitleString (index_title),
                               m_pChannels (p_channels)

{
    m_ChannelFontRenderer.loadFont ("font/neutrond.ttf", 32, true, true);
    m_TitleFontRenderer.loadFont ("font/neutrond.ttf", 48, true, true);
}

lcdtv::index_channel::~index_channel ()
{

}

void
lcdtv::index_channel::play()
{

}

void
lcdtv::index_channel::stop()
{

}

void
lcdtv::index_channel::update()
{

}

void
lcdtv::index_channel::draw (unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    ofBackground (0,0,0);
    ofSetColor (255,255,255);

    float title_x_offset = 300;
    float title_y_offset = 100;
    m_TitleFontRenderer.drawString (m_TitleString, x + title_x_offset, y + (title_y_offset * 2));

    lcdtv::ichannel *p_channel;
    float h_spacer = 100;
    float v_spacer = 60;
    float x_offset = 0.0f;
    float y_offset = 0.0f;
    for (unsigned int i = 0; i < m_pChannels->size(); i++) {
        p_channel = m_pChannels->at(i);
        x_offset = h_spacer;
        y_offset = (title_y_offset * 2.5) + (v_spacer * (i + 1));
        std::string idx_string (ofToString ((int) i));
        m_ChannelFontRenderer.drawString (idx_string, x + x_offset, y + y_offset);
        ofRectangle str_box = m_ChannelFontRenderer.getStringBoundingBox (idx_string, x + x_offset, y + y_offset);
        x_offset += h_spacer;
        p_channel->drawIDImage (x + x_offset, str_box.y, str_box.height, str_box.height);
        x_offset += h_spacer;
        m_ChannelFontRenderer.drawString (p_channel->getChannelName(), x + x_offset, y + y_offset);
    }
}
