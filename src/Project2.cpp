#include <iostream>
#include <fstream>
#include <vector>
#include "Pixel.h"
using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};

void WriteFile(string fileName, vector<Pixel> pixels, Header& header) {
    ofstream oFileLayer1("output/" + fileName + ".tga", ios::out | ios::binary);
    oFileLayer1.write(&header.idLength, sizeof(header.idLength));
    oFileLayer1.write(&header.colorMapType, sizeof(header.colorMapType));
    oFileLayer1.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
    oFileLayer1.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    oFileLayer1.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    oFileLayer1.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    oFileLayer1.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    oFileLayer1.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    oFileLayer1.write((char*)&header.width, sizeof(header.width));
    oFileLayer1.write((char*)&header.height, sizeof(header.height));
    oFileLayer1.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    oFileLayer1.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
    for (auto i : pixels) {
        oFileLayer1.write((char*)&(i.blue), sizeof(i.blue));
        oFileLayer1.write((char*)&(i.green), sizeof(i.green));
        oFileLayer1.write((char*)&(i.red), sizeof(i.red));
    }
    oFileLayer1.close();
}
void WriteChannelFiles(vector<vector<unsigned char>> channels, Header& header) {
    ofstream oFileLayer1("output/part8_b.tga", ios::out | ios::binary);
    oFileLayer1.write(&header.idLength, sizeof(header.idLength));
    oFileLayer1.write(&header.colorMapType, sizeof(header.colorMapType));
    oFileLayer1.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
    oFileLayer1.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    oFileLayer1.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    oFileLayer1.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    oFileLayer1.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    oFileLayer1.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    oFileLayer1.write((char*)&header.width, sizeof(header.width));
    oFileLayer1.write((char*)&header.height, sizeof(header.height));
    oFileLayer1.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    oFileLayer1.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
    for (auto i : channels.at(0)) {
        oFileLayer1.write((char*)&i, sizeof(i));
    }
    oFileLayer1.close();

    ofstream oFileLayer2("output/part8_g.tga", ios::out | ios::binary);
    oFileLayer2.write(&header.idLength, sizeof(header.idLength));
    oFileLayer2.write(&header.colorMapType, sizeof(header.colorMapType));
    oFileLayer2.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
    oFileLayer2.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    oFileLayer2.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    oFileLayer2.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    oFileLayer2.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    oFileLayer2.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    oFileLayer2.write((char*)&header.width, sizeof(header.width));
    oFileLayer2.write((char*)&header.height, sizeof(header.height));
    oFileLayer2.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    oFileLayer2.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
    for (auto i : channels.at(1)) {
        oFileLayer2.write((char*)&i, sizeof(i));
    }
    oFileLayer2.close();

    ofstream oFileLayer3("output/part8_r.tga", ios::out | ios::binary);
    oFileLayer3.write(&header.idLength, sizeof(header.idLength));
    oFileLayer3.write(&header.colorMapType, sizeof(header.colorMapType));
    oFileLayer3.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
    oFileLayer3.write((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    oFileLayer3.write((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    oFileLayer3.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
    oFileLayer3.write((char*)&header.xOrigin, sizeof(header.xOrigin));
    oFileLayer3.write((char*)&header.yOrigin, sizeof(header.yOrigin));
    oFileLayer3.write((char*)&header.width, sizeof(header.width));
    oFileLayer3.write((char*)&header.height, sizeof(header.height));
    oFileLayer3.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    oFileLayer3.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
    for (auto i : channels.at(2)) {
        oFileLayer3.write((char*)&i, sizeof(i));
    }
    oFileLayer3.close();
}

void ReadFile(string directory, string fileName, Header& header, vector<Pixel>& pixels) {
    ifstream fileLayer1(directory  + "/" + fileName + ".tga", std::ios::binary);

    fileLayer1.read(&header.idLength, sizeof(header.idLength));
    fileLayer1.read(&header.colorMapType, sizeof(header.colorMapType));
    fileLayer1.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
    fileLayer1.read((char*)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    fileLayer1.read((char*)&header.colorMapLength, sizeof(header.colorMapLength));
    fileLayer1.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
    fileLayer1.read((char*)&header.xOrigin, sizeof(header.xOrigin));
    fileLayer1.read((char*)&header.yOrigin, sizeof(header.yOrigin));
    fileLayer1.read((char*)&header.width, sizeof(header.width));
    fileLayer1.read((char*)&header.height, sizeof(header.height));
    fileLayer1.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    fileLayer1.read(&header.imageDescriptor, sizeof(header.imageDescriptor));

    unsigned char blue;
    unsigned char green;
    unsigned char red;

    for (int i = 0; i < (header.width * header.height); ++i) {
        fileLayer1.read((char*)&blue, sizeof(blue));
        fileLayer1.read((char*)&green, sizeof(green));
        fileLayer1.read((char*)&red, sizeof(red));
        Pixel newPixel(i, blue, green, red);
        pixels.push_back(newPixel);
    }
}
bool CheckImagesEquivalence(vector<Pixel> image1, vector<Pixel> image2, Header header1, Header header2) {
    if ((header1.idLength != header2.idLength) || (header1.colorMapType != header2.colorMapType) || (header1.dataTypeCode != header2.dataTypeCode) || (header1.colorMapOrigin != header2.colorMapOrigin) || (header1.colorMapLength != header2.colorMapLength) || (header1.colorMapDepth != header2.colorMapDepth) || (header1.xOrigin != header2.xOrigin) || (header1.yOrigin != header2.yOrigin) || (header1.width != header2.width) || (header1.height != header2.height) || (header1.bitsPerPixel != header2.bitsPerPixel) || (header1.imageDescriptor != header2.imageDescriptor)) { return false; }
    for (auto i : image1) {
        if ((i.blue != image2.at(i.number).blue) || (i.green != image2.at(i.number).green) || (i.red != image2.at(i.number).red)) { return false; }
    }
    return true;
}

vector<Pixel> Multiply(vector<Pixel> top_layer, vector<Pixel> bottom_layer) {
    vector<Pixel> newImage;
    for (auto i : bottom_layer) {
        unsigned char temp_blue = ((float)(i.blue) / 255.0) * (top_layer.at(i.number).blue) + 0.5f;
        unsigned char temp_green = ((float)(i.green) / 255.0) * (top_layer.at(i.number).green) + 0.5f;
        unsigned char temp_red = ((float)(i.red) / 255.0) * (top_layer.at(i.number).red) + 0.5f;
        Pixel newPixel(i.number, temp_blue, temp_green, temp_red);
        newImage.push_back(newPixel);
    }
    return newImage;
}
vector<Pixel> Screen(vector<Pixel> top_layer, vector<Pixel> bottom_layer) {
    vector<Pixel> newImage;
    for (auto i : bottom_layer) {
        unsigned char temp_blue = 0.5f + 255.0 * (1 - ((1 - (float)(i.blue) / 255.0) * (1 - ((float)top_layer.at(i.number).blue) / 255.0)));
        unsigned char temp_green = 0.5f + 255.0 * (1 - ((1 - (float)(i.green) / 255.0) * (1 - ((float)top_layer.at(i.number).green) / 255.0)));
        unsigned char temp_red = 0.5f + 255.0 * (1 - ((1 - (float)(i.red) / 255.0) * (1 - ((float)top_layer.at(i.number).red) / 255.0)));
        Pixel newPixel(i.number, temp_blue, temp_green, temp_red);
        newImage.push_back(newPixel);
    }
    return newImage;
}

vector<Pixel> Subtract(vector<Pixel> top_layer, vector<Pixel> bottom_layer) {
    vector<Pixel> newImage;
    for (auto i : bottom_layer) {
        unsigned char temp_blue;
        unsigned char temp_green;
        unsigned char temp_red;
        if (i.blue < (top_layer.at(i.number).blue)) { temp_blue = 0; }
        else { temp_blue = i.blue - (top_layer.at(i.number).blue); }
        if (i.green < (top_layer.at(i.number).green)) { temp_green = 0; }
        else { temp_green = i.green - (top_layer.at(i.number).green); }
        if (i.red < (top_layer.at(i.number).red)) { temp_red = 0; }
        else { temp_red = i.red - (top_layer.at(i.number).red); }
        Pixel newPixel(i.number, temp_blue, temp_green, temp_red);
        newImage.push_back(newPixel);
    }
    return newImage;
}
vector<Pixel> AddColor(vector<Pixel> pixels, string channel, int color_addition) {
    vector<Pixel> newImage;
    unsigned char temp_blue;
    unsigned char temp_green;
    unsigned char temp_red;
    if (channel == "blue") {
        for (auto i : pixels) {
            if (i.blue + color_addition > 255) { temp_blue = 255; }
            else { temp_blue = i.blue + color_addition; }
            Pixel newPixel(i.number, temp_blue, i.green, i.red);
            newImage.push_back(newPixel);
        }
    }
    else if (channel == "green") {
        for (auto i : pixels) {
            if (i.green + color_addition > 255) { temp_green = 255; }
            else { temp_green = i.green + color_addition; }
            Pixel newPixel(i.number, i.blue, temp_green, i.red);
            newImage.push_back(newPixel);
        }
    }
    else if (channel == "red") {
        for (auto i : pixels) {
            if (i.red + color_addition > 255) { temp_red = 255; }
            else { temp_red = i.red + color_addition; }
            Pixel newPixel(i.number, i.blue, i.green, temp_red);
            newImage.push_back(newPixel);
        }
    }
    return newImage;
}
vector<Pixel> ScaleColor(vector<Pixel> pixels, string channel, int color_scale) {
    vector<Pixel> newImage;
    unsigned char temp_blue;
    unsigned char temp_green;
    unsigned char temp_red;
    if (channel == "blue") {
        for (auto i : pixels) {
            if (i.blue * color_scale > 255) { temp_blue = 255; }
            else { temp_blue = i.blue * color_scale; }
            Pixel newPixel(i.number, temp_blue, i.green, i.red);
            newImage.push_back(newPixel);
        }
    }
    else if (channel == "green") {
        for (auto i : pixels) {
            if (i.green * color_scale > 255) { temp_green = 255; }
            else { temp_green = i.green * color_scale; }
            Pixel newPixel(i.number, i.blue, temp_green, i.red);
            newImage.push_back(newPixel);
        }
    }
    else if (channel == "red") {
        for (auto i : pixels) {
            if (i.red * color_scale > 255) { temp_red = 255; }
            else { temp_red = i.red * color_scale; }
            Pixel newPixel(i.number, i.blue, i.green, temp_red);
            newImage.push_back(newPixel);
        }
    }
    return newImage;
}
vector<vector<unsigned char>> SeperateColorChannels(vector<Pixel> pixels) {
    vector<vector<unsigned char>> seperated_channels;
    vector<unsigned char> blue_channel;
    vector<unsigned char> green_channel;
    vector<unsigned char> red_channel;
    for (auto i : pixels) {
        blue_channel.push_back(i.blue);
        blue_channel.push_back(i.blue);
        blue_channel.push_back(i.blue);
        green_channel.push_back(i.green);
        green_channel.push_back(i.green);
        green_channel.push_back(i.green);
        red_channel.push_back(i.red);
        red_channel.push_back(i.red);
        red_channel.push_back(i.red);
    }
    seperated_channels.push_back(blue_channel);
    seperated_channels.push_back(green_channel);
    seperated_channels.push_back(red_channel);
    return seperated_channels;
}
vector<Pixel> CombineColorChannels(vector<vector<Pixel>> color_channels) {
    vector<Pixel> combined_channel;
    unsigned char temp_blue;
    unsigned char temp_green;
    unsigned char temp_red;
    for (auto i : color_channels.at(0)) {
        temp_blue = i.blue;
        temp_green = color_channels.at(1).at(i.number).green;
        temp_red = color_channels.at(2).at(i.number).red;
        Pixel newPixel(i.number, temp_blue, temp_green, temp_red);
        combined_channel.push_back(newPixel);
    }
    return combined_channel;
}
vector<Pixel> FlipImage(vector<Pixel> pixels, Header header) {
    int total_pixels = header.width * header.height;
    vector<Pixel> new_image;
    for (int i = total_pixels - 1; i >= 0; --i) {
        new_image.push_back(pixels.at(i));
    }
    return new_image;
}
vector<Pixel> CombineFourImages(int width, vector<Pixel> bottom_left, vector<Pixel> bottom_right, vector<Pixel> top_left, vector<Pixel> top_right) {
    vector<Pixel> combined_image;
    for (int r = 0; r < width; ++r) {
        //Iterate through each row (bottom half)
        for (int ll = 0; ll < width; ++ll) {
            combined_image.push_back(bottom_left.at(ll + r * width));
        }
        for (int rr = 0; rr < width; ++rr) {
            combined_image.push_back(bottom_right.at(rr + r * width));
        }
    }
    for (int r = 0; r < width; ++r) {
        //Iterate through each row (top half)
        for (int ll = 0; ll < width; ++ll) {
            combined_image.push_back(top_left.at(ll + r * width));
        }
        for (int rr = 0; rr < width; ++rr) {
            combined_image.push_back(top_right.at(rr + r * width));
        }
    }
    return combined_image;
}
vector<Pixel> Overlay(vector<Pixel> top_layer, vector<Pixel> bottom_layer) {
    vector<Pixel> newImage;
    for (auto i : bottom_layer) {
        unsigned char temp_blue;
        unsigned char temp_green;
        unsigned char temp_red;
        if ((float)(i.blue) / 255.0 <= 0.5) { temp_blue = 2 * ((float)(i.blue) / 255.0) * (top_layer.at(i.number).blue) + 0.5f; }
        else { temp_blue = 0.5f+ 255.0 * (1 - 2 * ((1 - (float)(i.blue) / 255.0) * (1 - ((float)top_layer.at(i.number).blue) / 255.0))); }
        if ((float)(i.green) / 255.0 <= 0.5) { temp_green = 2 * ((float)(i.green) / 255.0) * (top_layer.at(i.number).green) + 0.5f; }
        else { temp_green = 0.5f+ 255.0 * (1 - 2 * ((1 - (float)(i.green) / 255.0) * (1 - ((float)top_layer.at(i.number).green) / 255.0))); }
        if ((float)(i.red) / 255.0 <= 0.5) { temp_red = 2 * ((float)(i.red) / 255.0) * (top_layer.at(i.number).red) + 0.5f; }
        else { temp_red = 0.5f+ 255.0 * (1 - 2 * ((1 - (float)(i.red) / 255.0) * (1 - ((float)top_layer.at(i.number).red) / 255.0))); }
        Pixel newPixel(i.number, temp_blue, temp_green, temp_red);
        newImage.push_back(newPixel);
    }
    return newImage;
}

int main()
{    
    cout << "Executing tasks..." << endl;
    /*======  TASK 1 ========*/
    Header layer1Header_1;
    vector<Pixel> layer1Pixels_1;
    ReadFile("input", "layer1", layer1Header_1, layer1Pixels_1);

    Header pattern1Header_1;
    vector<Pixel> pattern1Pixels_1;
    ReadFile("input", "pattern1", pattern1Header_1, pattern1Pixels_1);

    vector<Pixel> multiplied_image = Multiply(layer1Pixels_1, pattern1Pixels_1);

    WriteFile("part1", multiplied_image, layer1Header_1);
    cout << "Task 1 complete" << endl;


    /*======  TASK 2 ========*/
    Header layer2Header_2;
    vector<Pixel> layer2Pixels_2;
    ReadFile("input", "layer2", layer2Header_2, layer2Pixels_2);

    Header carHeader_2;
    vector<Pixel> carPixels_2;
    ReadFile("input", "car", carHeader_2, carPixels_2);

    vector<Pixel> subtracted_image = Subtract(layer2Pixels_2, carPixels_2);

    WriteFile("part2", subtracted_image, layer2Header_2);
    cout << "Task 2 complete" << endl;


    /*======  TASK 3 ========*/
    Header layer1Header_3;
    vector<Pixel> layer1Pixels_3;
    ReadFile("input", "layer1", layer1Header_3, layer1Pixels_3);

    Header pattern2Header_3;
    vector<Pixel> pattern2Pixels_3;
    ReadFile("input", "pattern2", pattern2Header_3, pattern2Pixels_3);

    multiplied_image = Multiply(layer1Pixels_3, pattern2Pixels_3);

    Header textHeader_3;
    vector<Pixel> textPixels_3;
    ReadFile("input", "text", textHeader_3, textPixels_3);

    vector<Pixel> screen_image = Screen(textPixels_3, multiplied_image);

    WriteFile("part3", screen_image, layer1Header_3);
    cout << "Task 3 complete" << endl;


    /*======  TASK 4 ========*/
    Header layer2Header_4;
    vector<Pixel> layer2Pixels_4;
    ReadFile("input", "layer2", layer2Header_4, layer2Pixels_4);

    Header circlesHeader_4;
    vector<Pixel> circlePixels_4;
    ReadFile("input", "circles", circlesHeader_4, circlePixels_4);

    multiplied_image = Multiply(layer2Pixels_4, circlePixels_4);

    Header pattern2Header_4;
    vector<Pixel> pattern2Pixels_4;
    ReadFile("input", "pattern2", pattern2Header_4, pattern2Pixels_4);

    subtracted_image = Subtract(pattern2Pixels_4, multiplied_image);

    WriteFile("part4", subtracted_image, layer2Header_4);
    cout << "Task 4 complete" << endl;


    /*======  TASK 5 ========*/
    Header layer1Header_5;
    vector<Pixel> layer1Pixels_5;
    ReadFile("input", "layer1", layer1Header_5, layer1Pixels_5);

    Header pattern1Header_5;
    vector<Pixel> pattern1Pixels_5;
    ReadFile("input", "pattern1", pattern1Header_5, pattern1Pixels_5);

    vector<Pixel> overlay_image = Overlay(layer1Pixels_5, pattern1Pixels_5);

    WriteFile("part5", overlay_image, layer1Header_5);
    cout << "Task 5 complete" << endl;


    /*======  TASK 6 ========*/
    Header carHeader_6;
    vector<Pixel> carPixels_6;
    ReadFile("input", "car", carHeader_6, carPixels_6);

    vector<Pixel> adjusted_image = AddColor(carPixels_6, "green", 200);

    WriteFile("part6", adjusted_image, carHeader_6);
    cout << "Task 6 complete" << endl;


    /*======  TASK 7 ========*/
    Header carHeader_7;
    vector<Pixel> carPixels_7;
    ReadFile("input", "car", carHeader_7, carPixels_7);

    adjusted_image = ScaleColor(carPixels_7, "red", 4);
    vector<Pixel> final_image = ScaleColor(adjusted_image, "blue", 0);

    WriteFile("part7", final_image, carHeader_7);
    cout << "Task 7 complete" << endl;


    /*======  TASK 8 ========*/
    Header carHeader_8;
    vector<Pixel> carPixels_8;
    ReadFile("input", "car", carHeader_8, carPixels_8);

    vector<vector<unsigned char>> seperated_channels = SeperateColorChannels(carPixels_8);

    WriteChannelFiles(seperated_channels, carHeader_8);
    cout << "Task 8 complete" << endl;


    /*======  TASK 9 ========*/
    Header redHeader_9;
    vector<Pixel> redPixels_9;
    ReadFile("input", "layer_red", redHeader_9, redPixels_9);

    Header greenHeader_9;
    vector<Pixel> greenPixels_9;
    ReadFile("input", "layer_green", greenHeader_9, greenPixels_9);

    Header blueHeader_9;
    vector<Pixel> bluePixels_9;
    ReadFile("input", "layer_blue", blueHeader_9, bluePixels_9);

    vector<vector<Pixel>> color_channels{ bluePixels_9 ,greenPixels_9, redPixels_9 };
    vector<Pixel> combined_channels = CombineColorChannels(color_channels);
    WriteFile("part9", combined_channels, redHeader_9);
    cout << "Task 9 complete" << endl;


    /*====== TASK 10 =====*/
    Header text2Header;
    vector<Pixel> text2Pixels;
    ReadFile("input", "text2", text2Header, text2Pixels);

    vector<Pixel> flipped_image = FlipImage(text2Pixels, text2Header);
    WriteFile("part10", flipped_image, text2Header);
    cout << "Task 10 complete" << endl;

    /*===== EXTRA CREDIT =======*/
    Header carHeader_ec;
    vector<Pixel> carPixels_ec;
    ReadFile("input", "car", carHeader_ec, carPixels_ec);

    Header circlesHeader_ec;
    vector<Pixel> circlePixels_ec;
    ReadFile("input", "circles", circlesHeader_ec, circlePixels_ec);

    Header pattern1Header_ec;
    vector<Pixel> pattern1Pixels_ec;
    ReadFile("input", "pattern1", pattern1Header_ec, pattern1Pixels_ec);

    Header textHeader_ec;
    vector<Pixel> textPixels_ec;
    ReadFile("input", "text", textHeader_ec, textPixels_ec);

    vector<Pixel> combined_image = CombineFourImages(textHeader_ec.width, textPixels_ec, pattern1Pixels_ec, carPixels_ec, circlePixels_ec);
    carHeader_ec.width *= 2;
    carHeader_ec.height *= 2;
    WriteFile("extracredit", combined_image, carHeader_ec);
    cout << "Extra credit task complete" << endl;

}