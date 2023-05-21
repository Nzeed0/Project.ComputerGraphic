import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

class Decode_Image extends JPanel{

    static int[][] arrayPic = new int [10000][10000];
    public static void getImg() throws IOException {
      final BufferedImage img = ImageIO.read(new File("./Test2.png"));
      for (int i = 0; i < img.getHeight(); i++) {
        for (int j = 0; j < img.getWidth(); j++) {
          final Color c = new Color(img.getRGB(j, i));
          arrayPic[i][j * 3] = c.getRed();
          arrayPic[i][(j * 3) + 1] = c.getGreen();
          arrayPic[i][(j * 3) + 2] = c.getBlue();
        }
      }

      for (int i = 0; i < img.getHeight(); i++) {
        for (int j = 0; j < img.getWidth(); j++) {
          if(arrayPic[i][j * 3] == 198 && arrayPic[i][(j * 3)+1] == 198 && arrayPic[i][(j * 3)+2] == 198) 
          {System.out.print("Currected Picture!");
           return;
          }
        }
      }
    }

    public static void main(String[] args) throws IOException {
      Decode_Image m = new Decode_Image();
      JFrame f = new JFrame();
      f.add(m);
      f.setSize(900, 900);
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      getImg();
    }


}