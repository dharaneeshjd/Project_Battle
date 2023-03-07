
<h2>Problem Statement:</h2>

A large war is raging in Valhalla. One of the viking tribes, the Bersekers have a big wall that covers the city on all sides. The wall was built by the Bersekers to protect against military incursions. For the purposes of this problem, the wall is a square. Berserkers are awesome craftsmen and they can quickly repair walls. Whenever a side is attacked successfully, the Wall on that side would be raised to the height sufficient to stop an identical attack in the future.

Valhalla was frequently attacked by nomadic tribes. For the purposes of this problem, we assume that each tribe attacks the wall with some weapon X, strength S (the strength defines the height at impact) and in a direction (N,S,E,W). The weapon has a magnitude of 1 and it is the strength that defines the attack. In order to repel the attack, the Wall must have height S all along the defended side of the wall. If the height on that side of the Wall is lower than needed, the attack will breach the Wall at this point and succeed. Note that even a successful attack does not damage the Wall. After the attack, every attacked fragment of the Wall that was lower than S is raised to height S — in other words, the Wall is increased in the minimal way that would have stopped the attack. Note that if two or more attacks happened on the exact same day, the Wall was raised only after they all resolved, and is raised in the minimum way that would stop all of them.

Assuming that initially the Wall was nonexistent (i.e., of height zero everywhere), and given the full description of all the nomadic tribes that attacked the Wall, determine how many of the attacks were successful. Weaponry has not advanced across the globe and thus all tribes have the same weapon X

<b>Example:</b>

<b>Input:</b>

Day 1: T1 - N - 3: T2 - S - 4: T3 - W - 2

Day 2: T1 - E - 4: T2 - N - 3: T3 - S - 2

Day 3: T1 - W - 3: T2 - E - 5: T3 - N – 2


<b>Output:</b>

6
