/*
Martin's father goes for a jog ever morning. Martin follows him several
minutes.His father starts at a position that is X1 meters away from his home and
runs rectilinear at a constant speed of V1 meters per step for N steps.

Martin is standing at X2 meters away from his home.He wonders how fast he
must run at some constant speed of V2 meters per step so as to maximize F,
where F equals the number of his father's footsteps that Martin will land on during
his run. It is given that the first step that Martin will land on, from his starting
point, will have been landed on by his father.

write algo to help Martin calculate F and V2
*/

import java.util.Scanner;

public class MartinsJog {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-->0){
            int x1 = scanner.nextInt();
            int x2 = scanner.nextInt();
            int v1 = scanner.nextInt();
            int steps = scanner.nextInt();

            int[] array = solve(x1,x2,v1,steps);

            System.out.println(array[0]+" "+array[1]);
        }
    }

    private static int[] solve(int x1, int x2, int v1, int n){
        /*
            result[0]: common steps;
            result[1]: v2;
        */
        int[] result = new int[2];
        int[] steps = new int[n+1];

        for (int i=0; i<=n; i++)
            steps[i] = x1 + v1*i - x2;

        for(int i=0; i<=n; i++){
            if(steps[i]<=0) continue;
            int v2 = steps[i];
            int count = 0;
            for(int j=i; j<=n; j++){
                if(steps[j]%v2 == 0)
                    count++;
            }
            if(result[0]<=count){
                result[0] = count;
                result[1] = v2;
            }
        }

        return result;
    }
}
