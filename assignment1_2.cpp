
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/video/background_segm.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

vector<long double> aa;

void get_frac(Mat frame){
  
  long double cc=0;
  for(int i=0;i<frame.rows;i++){
    for(int j=0;j<frame.cols;j++){
      Vec3b bgrPixel = frame.at<Vec3b>(i,j);
      cc+=bgrPixel.val[0];
      cc+=bgrPixel.val[1];
      cc+=bgrPixel.val[2];
    }
  }
  aa.push_back(cc);
}


int main(int argc, char* argv[])
{
  VideoCapture cap("trafficvideo.mp4"); 
  if (cap.isOpened() == false)  
  {
    cout << "Cannot open the video file" << endl;
    cin.get(); 
    return -1;
  }
  
  Mat bg;
  cap.read(bg);
  Mat bg_changed;
  cvtColor(bg,bg_changed,COLOR_BGR2GRAY);

  String window_name = "My First Video";
  String window_name2 = "Binary video";

  namedWindow(window_name, WINDOW_NORMAL);
  namedWindow(window_name2, WINDOW_NORMAL);

  int x0=472, y0=52, x1=472, y1=830, x2=800, y2=830, x3=800, y3=52;        
  vector<Point2f> a={Point2f(x0,y0),Point2f(x1,y1),Point2f(x2,y2),Point2f(x3,y3)};
  vector<Point2f> b={Point2f(984,204),Point2f(264,1068),Point2f(1542,1068),Point2f(1266,222)};

  Mat H=findHomography(b,a);
  warpPerspective(bg_changed,bg_changed,H,bg_changed.size());

  Rect region;                      //region shows the section of window which is to be cropped
  region.x=a[0].x;
  region.y=a[0].y;
  region.width=a[2].x-a[0].x;
  region.height=a[2].y-a[0].y;

  bg_changed = bg_changed(region);

  Mat prvs;
  bg_changed.copyTo(prvs);
  int count=0;



  while (true)
  {
    Mat frame;
    bool bSuccess = cap.read(frame); 
    if (bSuccess == false) 
    {
      cout << "Found the end of the video" << endl;
      break;
    }
    count++;
    if (count%5!=0) continue;
    
    Mat gray_frame;
    cvtColor(frame,gray_frame,COLOR_BGR2GRAY);
    //show the frame in the created window
    imshow(window_name, frame);
    warpPerspective(gray_frame,gray_frame,H,gray_frame.size());
    gray_frame = gray_frame(region);

    Mat img3;
    absdiff(gray_frame,bg_changed,img3);
      
    Mat img3_binary;
    threshold(img3, img3_binary, 40, 255, THRESH_BINARY);
    imshow(window_name2, img3_binary);
    get_frac(img3_binary);

    
    if (waitKey(10) == 27)
    {
      cout << "Esc key is pressed by user. Stopping the video" << endl;
      break;
    }
  }
  long double tot = (bg_changed.rows)*(bg_changed.cols)*3*255;
  ofstream answer;
  answer.open("output.txt");
  for(int i=0;i<aa.size();i++) answer<<aa[i]/tot<<"\n";
  answer.close();

  return 0;

}