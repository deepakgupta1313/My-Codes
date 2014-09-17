import java.util.*;
public class Execution {
  String avail;
  
  public long analyze(String[] code) {
    StringBuffer buf = new StringBuffer();
    for (int i = 0; i < code.length; ++i) buf.append(code[i]);
    avail = buf.toString();
    return count();
  }
  
  long count()
  {
    long result = 0;
    while (true) {
      String token = getToken();
      if (token == null || token.equals("}")) return result;
      if (token.equals("for")) {
        getToken();
        long factor = Long.parseLong(getToken());
        getToken(); // )
        getToken(); // {
        result += factor * count();
      }
      else if (token.equals("BASIC;")) {
        ++result;
      }
      else throw new IllegalArgumentException(token);
    }
  }
  
  String getToken()
  {
    while (avail.length() > 0) {
      if (avail.charAt(0) == ' ') {
        avail = avail.substring(1);
        continue;
      }
      if ("(){}".indexOf(avail.charAt(0)) >= 0) {
        char cc = avail.charAt(0);
        avail = avail.substring(1);
        return "" + cc;
      }
      if (avail.charAt(0) == 'B') {
        avail = avail.substring(6);
        return "BASIC;";
      }
      if (avail.charAt(0) == 'f') {
        avail = avail.substring(3);
        return "for";
      }
      String ss = "";
      while (avail.length() > 0 && (avail.charAt(0) >= '0' && avail.charAt(0) <= '9')) {
        ss += avail.charAt(0);
        avail = avail.substring(1);
      }
      if (ss.length() > 0) {
        return ss;
      }
      throw new IllegalArgumentException(avail);
    }
    return null;
  }
}