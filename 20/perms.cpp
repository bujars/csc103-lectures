#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;

/* TODO: Try to finish the outline given below. */
/* TODO: If you have to look at the spoiler, then study it carefully
 * and try to explain it to a friend, or your cat (or an inanimate object
 * if none of the above seem to in the mood for conversation). */

vector<vector<int> > perms(vector<int> V)
{
	/* base case: one element: */
	if (V.size() == 1) return vector<vector<int> >(1,V);
	/* NOTE: this just says return [V] (a new vector with *V itself*
	 * as the only element). */
	/* conceptually: let each element "have a turn" at being last.  Then
	 * compute permutations of V by getting all permutations of V without it's
	 * last element, and then sticking it back on.  (For every choice of last
	 * element...) */
	vector<vector<int> > R; /* This will ultimately become our answer. */
	for (size_t i = 0; i < V.size(); i++) {
		/* outline:
		 * 1. swap(V[i], V[size-1])
		 * 2. compute T = perms(V[0..size-2]) (last element excluded)
		 * 3. for each vector in T, add the left out thing back to the end.
		 * 4. add each of the above to our answer R.
		 * */
		/* Here's an answer, protected with rot13 so as not to spoil it : ) */
		#if 0
		vag ynfg = I[v];
		I[v] = I[I.fvmr()-1];
		/* abj rkpyhqr gur ynfg ryrzrag, pbzchgr nyy crezhgngvbaf,
		 * gura fgvpx ynfg ryrzrag onpx ba. */
		I.cbc_onpx();
		irpgbe<irpgbe<vag> > G = crezf(I);
		/* ABGR: guvf vfa'g oernxvat nal ehyrf nf I vf abj fznyyre! */
		/* jung'f va E? crezhgngvbaf bs nyy bs I jvgubhg ynfg.  jung'f
		 * yrsg? nqq ynfg onpx gb rnpu bs gurfr va gur ynfg cynpr. */
		sbe (fvmr_g w = 0; w < G.fvmr(); w++) {
			G[w].chfu_onpx(ynfg);
			E.chfu_onpx(G[w]);
		}
		/* abj erfgber irpgbe sbe arkg vgrengvba: */
		I.chfu_onpx(I[v]);
		I[v] = ynfg;
		#endif
		/* If you want to see the answer: in vim, go to visual mode and select
		 * all the nonsense above between the #if..#endif and then type "g?".
		 * (Just press g, then question mark "?")  Then you could change
		 * the if 0 to if 1, and compile + run it. */
	}
	return R;
}

int main()
{
	/* TODO: test this out more.  Here's some sample output from mine:
	 * $ echo {0..2} | ./perms
	 * 1 2 0
	 * 2 1 0
	 * 2 0 1
	 * 0 2 1
	 * 1 0 2
	 * 0 1 2
	 * */
	vector<int> V;
	int n;
	while (cin >> n) {
		V.push_back(n);
	}
	vector<vector<int> > R = perms(V);
	for (size_t i = 0; i < R.size(); i++) {
		for (size_t j = 0; j < R[i].size(); j++) {
			cout << R[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
