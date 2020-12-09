import net.sourceforge.tess4j.ITesseract;
import net.sourceforge.tess4j.Tesseract;
import net.sourceforge.tess4j.TesseractException;
import org.opencv.core.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Test01 {
    static {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
    }


    public static String captureScreen(String fileName, int leftX, int leftY, int rightX, int rightY) throws Exception {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Rectangle screenRectangle = new Rectangle(screenSize);
        Robot robot = new Robot();
        BufferedImage image = robot.createScreenCapture(screenRectangle);
        BufferedImage subimage = image.getSubimage(leftX, leftY, rightX, rightY);

        ImageIO.write(subimage, "png", new File(fileName));

        return fileName;
    }


    public static boolean captureScreen(String fileName) throws Exception {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Rectangle screenRectangle = new Rectangle(screenSize);
        Robot robot = new Robot();
        BufferedImage image = robot.createScreenCapture(screenRectangle);

        ImageIO.write(image, "png", new File(fileName));
        return true;
    }

    public static void template(int method, String screenPic, String needCompared, PictureRecognitionParameters point) throws Exception {
        //转换为RGB图
        Mat templete = Imgcodecs.imread(screenPic, Imgproc.COLOR_BGR2RGB);

        Mat demo = Imgcodecs.imread(needCompared);


        int width = templete.cols() - demo.cols();
        int height = templete.rows() - demo.rows();
        Mat result = new Mat(width, height, CvType.CV_32FC1);

        Mat templeteGray = new Mat();

        Mat demoGray = new Mat();

        Imgproc.cvtColor(templete, templeteGray, Imgproc.COLOR_RGB2GRAY);

        Imgproc.cvtColor(demo, demoGray, Imgproc.COLOR_RGB2GRAY);

        Imgproc.matchTemplate(templeteGray, demoGray, result, Imgproc.TM_CCOEFF_NORMED);

//        Core.normalize(result, result, 0, 1, Core.NORM_MINMAX, -1, new Mat());

        Core.MinMaxLocResult mmr = Core.minMaxLoc(result);

        double x, y;

        if (method == Imgproc.TM_SQDIFF_NORMED || method == Imgproc.TM_SQDIFF) {
            x = mmr.minLoc.x;
            y = mmr.minLoc.y;

        } else {
            x = mmr.maxLoc.x;
            y = mmr.maxLoc.y;

        }

//        System.out.println("x="+x);
//        System.out.println("y="+y);
//
//
//        System.out.println("max="+mmr.maxVal);
//        System.out.println("min="+mmr.minVal);
        point.setMax(mmr.maxVal);
        point.setMin(mmr.minVal);

        String subImg = captureScreen("images/5.png",
                (int) x, (int) y, demo.width(), demo.height());

        double compareResult = compareHist_2(needCompared, subImg);

        point.setX((int) x);
        point.setY((int) y);
        point.setMatchResult(compareResult);


//        Imgproc.rectangle(templete,new Point(x,y),new Point(x+demo.cols(),y+demo.rows()),new Scalar(0,0,255),2,Imgproc.LINE_AA);

//        Robot robot = new Robot();
//        if(compareResult>=0.08) {
//            robot.mouseMove((int) x + (demo.cols() / 2), (int) y + (demo.rows() / 2));
//            robot.mousePress(InputEvent.BUTTON1_MASK);
//            robot.mouseRelease(InputEvent.BUTTON1_MASK);
//        }
//        HighGui.imshow("",templete);


    }

    public static double compareHist_2(String name1, String name2) {
        Mat src_1 = Imgcodecs.imread(name1);// 图片 1
        Mat src_2 = Imgcodecs.imread(name2);// 图片 2

        Mat hvs_1 = new Mat();
        Mat hvs_2 = new Mat();
        //图片转HSV
        Imgproc.cvtColor(src_1, hvs_1, Imgproc.COLOR_BGR2HSV);
        Imgproc.cvtColor(src_2, hvs_2, Imgproc.COLOR_BGR2HSV);

        Mat hist_1 = new Mat();
        Mat hist_2 = new Mat();

        //直方图计算
        Imgproc.calcHist(Stream.of(hvs_1).collect(Collectors.toList()), new MatOfInt(0), new Mat(), hist_1, new MatOfInt(255), new MatOfFloat(0, 256));
        Imgproc.calcHist(Stream.of(hvs_2).collect(Collectors.toList()), new MatOfInt(0), new Mat(), hist_2, new MatOfInt(255), new MatOfFloat(0, 256));

        //图片归一化
        Core.normalize(hist_1, hist_1, 1, hist_1.rows(), Core.NORM_MINMAX, -1, new Mat());
        Core.normalize(hist_2, hist_2, 1, hist_2.rows(), Core.NORM_MINMAX, -1, new Mat());

        //直方图比较
//        double a = Imgproc.compareHist(hist_1,hist_1,Imgproc.CV_COMP_CORREL);
        double b = Imgproc.compareHist(hist_1, hist_2, Imgproc.CV_COMP_CORREL);

        return b;

    }

    public static void main(String[] args) throws Exception {
        File file = new File("images/study.txt");
        HashMap<String,Double> hashMap = null;
        if(file.exists()){
            FileInputStream fs = new FileInputStream("images/study.txt");

            ObjectInputStream ois = new ObjectInputStream(fs);
            hashMap = (HashMap<String, Double>) ois.readObject();
            System.out.println("读取成功");
            System.out.println(hashMap.size());

        }

        PictureRecognitionParameters pictureRecognitionParameters = new PictureRecognitionParameters();
        Robot robot = new Robot();
        while(true) {
            while (true) {
                boolean flag = captureScreen("images/fullScreen.png");
                if (flag) {
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/search.png", pictureRecognitionParameters);
                    System.out.println(pictureRecognitionParameters.matchResult);
                    Mat imread = Imgcodecs.imread("images/5.png");
                    Double aDouble = hashMap.get(imread.dump());
                    System.out.println("myPoint.max=" + pictureRecognitionParameters.max);
                    if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.8) {

                        break;
                    }
                }
            }


            System.out.println(pictureRecognitionParameters.matchResult);

            if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.8) {
                robot.mouseMove(pictureRecognitionParameters.x, pictureRecognitionParameters.y);
                robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                robot.delay(1000);
                String findResource = "我的资源";
                setSysClipboardText(findResource);
                robot.keyPress(KeyEvent.VK_META);
                robot.delay(1000);
                robot.keyPress(KeyEvent.VK_V);
                robot.delay(1000);
                robot.keyRelease(KeyEvent.VK_V);
                robot.keyRelease(KeyEvent.VK_META);
                robot.delay(1000);
                robot.keyPress(KeyEvent.VK_ENTER);


                robot.keyRelease(KeyEvent.VK_ENTER);


                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/select.png", pictureRecognitionParameters);

                    System.out.println("找select=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.97 && pictureRecognitionParameters.getMax() >= 0.8) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x, pictureRecognitionParameters.y);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }

                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/shared.png", pictureRecognitionParameters);
                    System.out.println("找shared=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.09 && pictureRecognitionParameters.getMax() >= 0.9) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x, pictureRecognitionParameters.y);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }


                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/time.png", pictureRecognitionParameters);
                    System.out.println("找time=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.9) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x + 61, pictureRecognitionParameters.y + 13);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }


                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/link.png", pictureRecognitionParameters);
                    System.out.println("找link=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.9) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x + 65, pictureRecognitionParameters.y + 23);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }

                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/password.png", pictureRecognitionParameters);
                    System.out.println("找password=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.9) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x + 20, pictureRecognitionParameters.y + 10);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }

                while (true) {
                    captureScreen("images/fullScreen.png");
                    template(Imgproc.TM_CCOEFF_NORMED,
                            "images/fullScreen.png",
                            "images/close.png", pictureRecognitionParameters);
                    System.out.println("找close=" + pictureRecognitionParameters.getMatchResult());
                    System.out.println(pictureRecognitionParameters.getMax());
                    if (pictureRecognitionParameters.matchResult >= 0.4 && pictureRecognitionParameters.getMax() >= 0.9) {
                        robot.delay(1500);
                        robot.mouseMove(pictureRecognitionParameters.x + 10, pictureRecognitionParameters.y + 10);
                        robot.mousePress(InputEvent.BUTTON1_DOWN_MASK);
                        robot.mouseRelease(InputEvent.BUTTON1_DOWN_MASK);
                        break;
                    }

                }



                String str = getSysClipboardText();
                String subStr = str.substring(3, str.length() - 9);
                System.out.println(subStr);




                while(true){
                    boolean linkState = Test02.getLinkState(subStr);
                    if(linkState){
                        System.out.println(new Date()+"循环检测链接="+subStr+"有效");
                    }else{
                        System.out.println(new Date()+"循环检测链接="+subStr+"失效");
                        setSysClipboardText(findResource);
                        Thread.sleep(2000);
                        break;
                    }
                }

            }

        }



    }

    public static String getSysClipboardText() {
        String ret = "";
        Clipboard sysClip = Toolkit.getDefaultToolkit().getSystemClipboard();
        // 获取剪切板中的内容
        Transferable clipTf = sysClip.getContents(null);

        if (clipTf != null) {
            // 检查内容是否是文本类型
            if (clipTf.isDataFlavorSupported(DataFlavor.stringFlavor)) {
                try {
                    ret = (String) clipTf
                            .getTransferData(DataFlavor.stringFlavor);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }

        return ret;
    }


    public static boolean getLinkState(String link){
        Boolean isclosed = null;

        try {
            isclosed = true; //标志是否失效，默认不失效
            URL url = new URL(link);//这里输入你要查询的链接
            try {
                InputStream is = url.openStream();
                InputStreamReader isr = new InputStreamReader(is, "utf-8");
                BufferedReader br = new BufferedReader(isr);
                StringBuilder sb = new StringBuilder();
                String data = br.readLine();
                while (data != null) {
                    data = br.readLine();
                    sb.append(data);
                }
                br.close();
                isr.close();
                is.close();
                String finaldata = sb.toString();
                if (finaldata.contains("分享的文件已经被取消了") || finaldata.contains("此链接分享内容可能因为涉及侵权") || finaldata.contains("你所访问的页面不存在了"))
                    isclosed = false;
                if (isclosed == true) {

                } else {
                    System.out.println("该链接已失效！");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }


        } catch (MalformedURLException e) {
            e.printStackTrace();
        }


        return isclosed;

    }


    public static String findString(String stringPic){
        String path = stringPic;

        String languagePath = "/Users/virtualman/Downloads/tessdata";




        File file = new File(path);

        ITesseract instance = new Tesseract();

        instance.setDatapath(languagePath);

        instance.setLanguage("chi_sim");

        String result =null;

        try {

            result = instance.doOCR(file);

        }catch(TesseractException e){
            e.printStackTrace();
        }


        System.out.println("result: ");
        System.out.println(result);
        return result;
    }

    public static void study() throws Exception {
        //对象序列化


        File exit = new File("images/study.txt");





        PictureRecognitionParameters pictureRecognitionParameters = new PictureRecognitionParameters();
        HashMap<String, Double> hashMap = new HashMap();
        int curSize = 0;
        if(exit.exists()){
            FileInputStream fs = new FileInputStream("images/study.txt");

            ObjectInputStream ois = new ObjectInputStream(fs);
            hashMap = (HashMap<String, Double>) ois.readObject();
            System.out.println("读取成功");
            System.out.println(hashMap.size());
            curSize = hashMap.size();
        }



        while(true) {
            captureScreen("images/fullScreen.png");
            Mat src = null;
            for(int i=0;i<50;i++) {
                template(Imgproc.TM_CCOEFF_NORMED,
                        "images/fullScreen.png",
                        "images/search.png", pictureRecognitionParameters);
                src = Imgcodecs.imread("images/5.png");
                System.out.println(pictureRecognitionParameters.matchResult);
                if(pictureRecognitionParameters.matchResult>=0.98)
                    Imgcodecs.imwrite("images/study/"+i+".png",src);
            }


            Robot robot = new Robot();
            if(hashMap.get(src.dump())==null) {
                robot.mouseMove(pictureRecognitionParameters.x, pictureRecognitionParameters.y);
            }
            Scanner sc = new Scanner(System.in);

            System.out.println("是否保留?,是打1 不是打0");
            int i = sc.nextInt();
            Thread.sleep(3000);
            if(i==1) {
                hashMap.put(src.dump(), pictureRecognitionParameters.matchResult);
                System.out.println("hash="+hashMap.get(src.dump()));
                System.out.println(hashMap.size());
                FileOutputStream fo = new FileOutputStream("images/study.txt");
                ObjectOutputStream oos = new ObjectOutputStream(fo);
                oos.writeObject(hashMap);
                oos.writeBoolean(true);
                oos.flush();
                break;

            }else{

            }


        }





    }


    public static void findSuface(String findPic, String comparePic) {
        Mat src = Imgcodecs.imread(comparePic);
        Mat dst = new Mat();
        Imgproc.cvtColor(src, dst, Imgproc.COLOR_BGR2GRAY);
        Imgproc.threshold(dst, dst, 250, 255, Imgproc.THRESH_BINARY_INV);
        Imgcodecs.imwrite("images/test.png", dst);
        java.util.List<MatOfPoint> matOfPoint = new ArrayList<MatOfPoint>();
        Mat fcMat = new Mat();

        Imgproc.findContours(dst, matOfPoint, fcMat, 2, 1);

        Mat src2 = Imgcodecs.imread(findPic);
        Mat dst2 = new Mat();
        Imgproc.cvtColor(src2, dst2, Imgproc.COLOR_BGR2GRAY);
        Imgproc.threshold(dst2, dst2, 250, 255, Imgproc.THRESH_BINARY_INV);
        Imgcodecs.imwrite("images/test2.png", dst2);
        java.util.List<MatOfPoint> matOfPoint2 = new ArrayList<MatOfPoint>();
        Mat fcMat2 = new Mat();

        Imgproc.findContours(dst2, matOfPoint2, fcMat2, 2, 1);

//
//        for(int i=0;i<matOfPoint.size();i++) {
//            Imgproc.drawContours(src, matOfPoint, i, new Scalar(0, 255, 0), 2);
//        }
//        Imgcodecs.imwrite("images/contours.png",src);
//
//
//        for(int i=0;i<matOfPoint2.size();i++) {
//            Imgproc.drawContours(src2, matOfPoint2, i, new Scalar(0, 255, 0), 2);
//        }
//        Imgcodecs.imwrite("images/contours2.png",src2);
//
//        double sum=0;
//        for (MatOfPoint ofPoint : matOfPoint2) {
//
//            for(MatOfPoint for2maMatOfPoint : matOfPoint){
//                double result = Imgproc.matchShapes(ofPoint,for2maMatOfPoint,Imgproc.CV_CONTOURS_MATCH_I1,2);
//                System.out.println(result);
//                sum += result;
//            }
//
//
//        }
//        System.out.println("sum="+sum);



    }

    public static void setSysClipboardText(String writeMe) {
        Clipboard clip = Toolkit.getDefaultToolkit().getSystemClipboard();
        Transferable tText = new StringSelection(writeMe);
        clip.setContents(tText, null);
    }

}
