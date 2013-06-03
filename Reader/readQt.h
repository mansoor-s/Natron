//  Powiter
//
//  Created by Alexandre Gauthier-Foichat on 06/12
//  Copyright (c) 2013 Alexandre Gauthier-Foichat. All rights reserved.
//  contact: immarespond at gmail dot com

#ifndef __PowiterOsX__ReadQt__
#define __PowiterOsX__ReadQt__
#include "Reader/Read.h"
#include <QtCore/QMutex>
#include <iostream>
#include <cstdio>
#include <QtGui/QImage>



class ReadQt : public Read {

    QImage* _img;
    QString filename;
public:
    static Read* BuildRead(Reader* reader){return new ReadQt(reader);}
    
    ReadQt(Reader* op);
    virtual ~ReadQt();
    /*Should return the list of file types supported by the decoder: "png","jpg", etc..*/
    virtual std::vector<std::string> fileTypesDecoded(){
        std::vector<std::string> out;
        out.push_back("jpg");
        out.push_back("bmp");
        out.push_back("jpeg");
        out.push_back("png");
        out.push_back("gif");
        out.push_back("pbm");
        out.push_back("pgm");
        out.push_back("ppm");
        out.push_back("xbm");
        out.push_back("xpm");
        return out;
    };
    
    /*Should return the name of the reader : "ffmpeg", "OpenEXR" ...*/
    virtual std::string decoderName(){return "QImage (Qt)";}
    virtual void engine(int y,int offset,int range,ChannelMask channels,Row* out);
    virtual bool supports_stereo();
    virtual void readHeader(const QString filename,bool openBothViews);
    virtual void readAllData(bool openBothViews);
    virtual bool supportsScanLine(){return false;}
    virtual void make_preview();
    virtual void initializeColorSpace();
};

#endif /* defined(__PowiterOsX__ReadQt__) */
