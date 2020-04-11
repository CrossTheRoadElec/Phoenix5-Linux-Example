import java.nio.charset.StandardCharsets;

import com.ctre.phoenix.platform.can.PlatformCAN;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

public class Example {
    public static void main(String[] args) {
        /* Init Code */
        PlatformCAN.setCANInterface(toCPPString("can0"));

        TalonSRX _talon = new TalonSRX(1);

        programSleep(2000); //give Phoenix time to finish init

        /* Looped Code */
        while(true) {

            com.ctre.phoenix.unmanaged.Unmanaged.feedEnable(100);

            programSleep(10);
        }
    }

    private static char[] toCPPString(String s) {
        byte[] stringBytes = s.getBytes(StandardCharsets.UTF_8);
        char[] cppString = new char[stringBytes.length / 2 + 1];

        int i = 0;
        int j = 0;
        while (j < stringBytes.length) {
            cppString[i] = (char)(stringBytes[j]);
            if (j < stringBytes.length + 1) {
                cppString[i] |= stringBytes[j + 1] << 8;
            }
            i++;
            j += 2;
        }
        return cppString;
    }

    private static void programSleep(int timeMs) {
        try {
            Thread.sleep(timeMs);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
