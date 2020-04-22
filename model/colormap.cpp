#include "colormap.h"
#include <QDebug>

ColorMap::ColorMap()
{
    initColorMap();
}

QColor ColorMap::color(int value)
{
#if 1
    if(value < 100 && value > 0)
    {
        return m_colorMap[value];
    }
    else
    {
        return QColor(255, 255, 255, 0);
    }
#else
    if(value <= 100 && value > 0)
    {
        return m_colorMap[100 - value];
    }
    else
    {
        return QColor(255, 255, 255, 0);
    }
#endif
}

void ColorMap::initColorMap()
{
    m_colorMap.append(QColor(53		,42		,135));
    m_colorMap.append(QColor(54		,46		,143));
    m_colorMap.append(QColor(54		,50		,151));
    m_colorMap.append(QColor(54		,54		,159));
    m_colorMap.append(QColor(54		,58		,167));
    m_colorMap.append(QColor(53		,62		,175));
    m_colorMap.append(QColor(51		,66		,183));
    m_colorMap.append(QColor(48		,71		,192));
    m_colorMap.append(QColor(43		,75		,200));
    m_colorMap.append(QColor(36		,80		,208));
    m_colorMap.append(QColor(26		,86		,216));
    m_colorMap.append(QColor(15		,92		,221));
    m_colorMap.append(QColor(6		,97		,224));
    m_colorMap.append(QColor(2		,100	,225));
    m_colorMap.append(QColor(1		,104	,225));
    m_colorMap.append(QColor(3		,107	,225));
    m_colorMap.append(QColor(5		,110	,224));
    m_colorMap.append(QColor(8		,112	,223));
    m_colorMap.append(QColor(10		,115	,221));
    m_colorMap.append(QColor(13		,117	,220));
    m_colorMap.append(QColor(15		,120	,219));
    m_colorMap.append(QColor(17		,122	,217));
    m_colorMap.append(QColor(18		,125	,216));
    m_colorMap.append(QColor(19		,127	,215));
    m_colorMap.append(QColor(20		,130	,213));
    m_colorMap.append(QColor(20		,132	,212));
    m_colorMap.append(QColor(20		,135	,211));
    m_colorMap.append(QColor(19		,138	,211));
    m_colorMap.append(QColor(17		,141	,210));
    m_colorMap.append(QColor(15		,144	,210));
    m_colorMap.append(QColor(12		,148	,210));
    m_colorMap.append(QColor(10		,151	,209));
    m_colorMap.append(QColor(8		,154	,209));
    m_colorMap.append(QColor(7		,156	,207));
    m_colorMap.append(QColor(6		,159	,206));
    m_colorMap.append(QColor(6		,161	,204));
    m_colorMap.append(QColor(6		,163	,202));
    m_colorMap.append(QColor(6		,165	,200));
    m_colorMap.append(QColor(6		,167	,197));
    m_colorMap.append(QColor(6		,169	,195));
    m_colorMap.append(QColor(8		,171	,192));
    m_colorMap.append(QColor(10		,172	,189));
    m_colorMap.append(QColor(13		,174	,186));
    m_colorMap.append(QColor(17		,175	,183));
    m_colorMap.append(QColor(21		,177	,180));
    m_colorMap.append(QColor(26		,178	,177));
    m_colorMap.append(QColor(31		,179	,173));
    m_colorMap.append(QColor(36		,181	,170));
    m_colorMap.append(QColor(42		,182	,166));
    m_colorMap.append(QColor(48		,183	,163));
    m_colorMap.append(QColor(54		,185	,159));
    m_colorMap.append(QColor(60		,186	,155));
    m_colorMap.append(QColor(67		,187	,151));
    m_colorMap.append(QColor(74		,188	,147));
    m_colorMap.append(QColor(81		,189	,143));
    m_colorMap.append(QColor(89		,189	,140));
    m_colorMap.append(QColor(96		,190	,136));
    m_colorMap.append(QColor(104	,190	,132));
    m_colorMap.append(QColor(112	,191	,129));
    m_colorMap.append(QColor(119	,191	,126));
    m_colorMap.append(QColor(126	,191	,123));
    m_colorMap.append(QColor(133	,191	,120));
    m_colorMap.append(QColor(140	,191	,117));
    m_colorMap.append(QColor(146	,191	,114));
    m_colorMap.append(QColor(153	,191	,112));
    m_colorMap.append(QColor(159	,190	,109));
    m_colorMap.append(QColor(165	,190	,107));
    m_colorMap.append(QColor(171	,190	,104));
    m_colorMap.append(QColor(177	,189	,102));
    m_colorMap.append(QColor(182	,189	,100));
    m_colorMap.append(QColor(188	,189	,98 ));
    m_colorMap.append(QColor(193	,188	,95 ));
    m_colorMap.append(QColor(199	,188	,93 ));
    m_colorMap.append(QColor(204	,187	,91 ));
    m_colorMap.append(QColor(209	,187	,89 ));
    m_colorMap.append(QColor(215	,186	,87 ));
    m_colorMap.append(QColor(220	,186	,84 ));
    m_colorMap.append(QColor(225	,185	,82 ));
    m_colorMap.append(QColor(230	,185	,80 ));
    m_colorMap.append(QColor(235	,185	,77 ));
    m_colorMap.append(QColor(240	,185	,74 ));
    m_colorMap.append(QColor(245	,186	,71 ));
    m_colorMap.append(QColor(250	,187	,67 ));
    m_colorMap.append(QColor(253	,189	,63 ));
    m_colorMap.append(QColor(254	,192	,58 ));
    m_colorMap.append(QColor(255	,196	,55 ));
    m_colorMap.append(QColor(254	,199	,51 ));
    m_colorMap.append(QColor(253	,202	,48 ));
    m_colorMap.append(QColor(252	,206	,46 ));
    m_colorMap.append(QColor(250	,209	,43 ));
    m_colorMap.append(QColor(249	,212	,41 ));
    m_colorMap.append(QColor(247	,216	,38 ));
    m_colorMap.append(QColor(246	,219	,35 ));
    m_colorMap.append(QColor(245	,223	,33 ));
    m_colorMap.append(QColor(245	,227	,30 ));
    m_colorMap.append(QColor(244	,231	,27 ));
    m_colorMap.append(QColor(245	,236	,24 ));
    m_colorMap.append(QColor(246	,241	,21 ));
    m_colorMap.append(QColor(247	,246	,17 ));
    m_colorMap.append(QColor(249	,251	,14 ));
}
