import java.util.*;

public class B {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt(), c = sc.nextInt();
		char g[][] = new char[r][];
		for(int i=0;i<r;i++) {
			g[i] = sc.next().toCharArray();
		}
		boolean f = true;
		for(int i=0;i<r;i++){
			for(int j = i+1;j<r;j++){
				int cntsame = 0;
				int cnt1=0;
				int cnt2=0;
				
				for(int k = 0;k<c;k++){
					if(g[i][k]=='#' && g[j][k]=='#')
						cntsame++;
					if(g[i][k]=='#')
						cnt1++;
					if(g[j][k]=='#')
						cnt2++;
					
				}
				
				if(cntsame != 0 && (cnt1!=cntsame || cnt2!=cntsame))
					f = false;
			}
		}
		
		System.out.println(f?"Yes":"No");
	}
}