#include <iostream>
#include "include.h"

using namespace cv;
using namespace std;
int main()
{
    Mat src = imread("./lenna.png");
    Mat sample = src.clone();
    cout << sample.size().area() << endl;
    cout << sample.rows << endl;
    cout << sample.cols << endl;
    uchar* pointer = sample.ptr<uchar>(0);
    for (int i = 0; i < sample.size().area(); i++)
    {
        pointer[i] = 0;
    }
    imshow("Pixel access ptr<uchar>(0)", sample);
    waitKey(0);

    Mat sample2 = src.clone();
    for (int j = 0; j < sample.rows; j++)
    {
        uchar* pointer2 = sample.ptr<uchar>(j);
        for (int i = 0; i < sample.cols; i++)
        {
            pointer2[i] = 0;
        }
    }
    imshow("Pixel access ptr<uchar>(j)", sample2);
    waitKey(0);

    Mat set_sample = src.clone();
    set_sample.setTo(0);
    imshow("Pixel access setTo", set_sample);
    waitKey(0);

    Mat src1 = src.clone();
    for (int j = 0; j < src1.rows; j++)
    {
        for (int i = 0; i < src1.cols; i++)
        {
            for (int c = 0; c < 3; ++c)
            {
                src1.at<Vec3b>(j,i)[c] = 0;
            }

        }
    }
    imshow("Pixel access at<Vec3b>(j,i)[c]", src1);
    waitKey(0);

    Mat src2 = src.clone();
    for (int j = 0; j < src2.rows; j++)
    {
        for (int i = 0; i < src2.cols; i++)
        {
            for (int c = 0; c < src2.channels(); ++c)
            {
                src2.at<uchar >(j,3*i+c) = 0;
            }

        }
    }
    imshow("Color image processing at<uchar>(j,3*i+c)", src2);
    waitKey(0);

    Mat src3 = src.clone();
    uchar* ptr = src3.ptr<uchar>(0);
    for (int i = 0; i < src3.size().area()*src3.channels(); ++i)
    {
        ptr[i] = 0;
    }
    imshow("Color image processing ptr<uchar>", src3);
    waitKey(0);

    vector<Mat> mat;
    split(src, mat);

    for (int j = 0; j < src.rows; j++)
    {
        for (int i = 0; i < src.cols; i++)
        {
            mat[0].at<uchar>(j,i) = 0;
            mat[1].at<uchar>(j,i) = 0;
            mat[2].at<uchar>(j,i) = 0;
        }
    }

    Mat result;
    merge(mat, result);
    imshow("Color image processing merge", result);
    waitKey(0);

    Mat set_mat;
    set_mat.setTo(0);
    imshow("Color image processing setTo(0)", set_mat);
    waitKey(0);

    return 0;

}
