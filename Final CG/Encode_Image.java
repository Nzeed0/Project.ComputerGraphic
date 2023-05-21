import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

class Encode_Image extends JPanel{

    static int[][] arrayPic = new int [10000][10000];
    public static void getImg() throws IOException {
      final BufferedImage img = ImageIO.read(new File("./gg.jpg"));
      for (int i = 0; i < img.getHeight(); i++) {
        for (int j = 0; j < img.getWidth(); j++) {
          final Color c = new Color(img.getRGB(j, i));
          arrayPic[i][j * 3] = c.getRed();
          arrayPic[i][(j * 3) + 1] = c.getGreen();
          arrayPic[i][(j * 3) + 2] = c.getBlue();
        }
      }
    }

    public void paintComponent(Graphics g) {
      for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
          g.setColor(new Color(arrayPic[i][j * 3], arrayPic[i][(j * 3) + 1], arrayPic[i][(j * 3) + 2]));
          g.fillRect(j, i, 1, 1);
        }
      }
      g.setColor(new Color(198,198,198));
      g.fillRect(5, 580, 1, 1);
    }

    public static void saveImage(String name,String type,BufferedImage Save) {
      try{
        ImageIO.write(Save, type, new File(name+"."+type));
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    public static BufferedImage createImage(JPanel panel) {
      int w = panel.getWidth();
      int h = panel.getHeight();
      BufferedImage bi = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
      Graphics2D g = bi.createGraphics();
      panel.paint(g);
      g.dispose();
      return bi;
  }

    public static void main(String[] args) throws IOException {
      Encode_Image m = new Encode_Image();
      JFrame f = new JFrame();
      f.add(m);
      f.setSize(900, 900);
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      f.setVisible(true);
      getImg();
      saveImage("Test2", "png", createImage(m));
    }


}