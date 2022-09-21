# CSinterview_question保研过程中的一些prepare
### tips：readme记录一些计算机保研面试中老师问的和自己准备的一些专业性的问题，关于项目的/一些家常的/一些专业性很低的问题除外。给自己查漏补缺用，有后缀表示考察学校。
### tips：Algorithm文件夹中放了洛谷模板题刷题的代码，为机试做准备，不定时更新。
### tips：语音文件夹放了入坑语音的学习过程


#### 1.贪心算法一定取到最优解吗？（hit）
答：不是，只有当问题满足最优子结构（当一个问题的子问题，贪心的选择比非贪心的选择更好）的时候才满足。（老师好像要的是给出一种通用的证明，我觉得得具体问题具体看。）
#### 2.分析一下深度可分离卷积
答：首先理解一下torch.nn.Conv2d(in_channels, out_channels, kernel_size, stride=1, padding=0)是怎么通过一个普通的卷积操作来改变信道数的。这里的输出信道数其实就是卷积核的个数，一个彩色图像的卷积核其实是三维立体的，而不是单纯二维的。例如一个一百通道的图片，经过一个尺寸3\*3的卷积核，实际上是经过一个3\*3\*100的卷积核，输入100张信道分别和“100张（100个信道，其实100加起来是一个卷积核）”3*3卷积核相乘，再融合变成一张特征图。这个特征图（此时只有1信道）。所以多少个卷积核就有多少个特征图，就可以输出多少信道。深度可分离卷积其实为了（模型压缩使用的，精度换参数量）。他由两部分构成，空间分离卷积和点卷积。空间分离卷积中的卷积核是二维的，（可以理解为卷积核的信道数是1）。并且空间分离卷积中的卷积核数量必须等于输入图片的信道数，这样保证了输出输入信道数一样（注意此时没有普通卷积中的融合过程）。但是这时候有个很大的问题是一个图像中的各个信道之间信息交互并没有学习到，所有后面加了一个点卷积，点卷积其实是一个（普通的三维！）1\*1卷积核。他会有融合过程，既最大程度保留信息又解决了之前所说的融合问题，而且既然是普通的三维卷积，还可以通过卷积核的数目来改变输出信道。
#### 3.分析一下空洞卷积（p，更大感受野，添0）
#### 4.分析一下各种归一化，batch norm，layer norm，instance norm，group norm
答：批归一化是将同一类信道（比如红色）一个batch_size中所有图片矩阵进行归一化，层归一化是一张图片所有信道，IN是一张图片一个信道，GN是介于LN和IN之间。
#### 5.分析一下准确率，精准率，召回率，F1-score
答：理解TP，FP，TN，FN的概念（TF表示预测结果是否正确，P表示预测的结果是正样本（实际可正可负），F反之）。准确率就是预测正确占所有样本的比例。精准率是预测为正样本且预测正确占预测为正样本的比例（多预测了）。召回率是预测为正样本且预测正确占实际为正样本的比例（少预测了）。F1-score是精准率和召回率的调和平均。
#### 6.分析一下直接插入排序，希尔排序，冒泡排序，快速排序，简单选择排序，堆排序，归并排序（p稳定性，时间复杂度，快排和堆排序都是不稳定且为O（nlogn）的，手撕快排代码）
#### 7.分析一下最原始的transformer
答：Sequence to Sequence引出，对比RNN能够并行计算。QKV来进行矩阵的操作。Q和每个k相乘得到他与当前位置的距离的结构，然后乘以v。然后经过softmax得到最终的结果。每个q都如此，即得到了与rnn相同的结果。然后还有一部分位置编码来解决A and B和B and A的问题，在构件编码器和解码器的过程中，还有一些残差连接，全连接，归一化等等不做赘述。
#### 8.分析一下支持向量机
答：如何设计一个超平面将两类数据分隔开来。一个好的超平面要有较好的margin，间隔的最中间就是我们的决策边界（超平面），距离决策边界最近的点称之为支持向量（但是这样支持向量岂不是只有很少的点？后面软间隔会解决这个问题）。这样我们就转化为了求决策超平面，正超平面，负超平面的系数的问题。
软间隔就是支持向量并不一定是距离决策边界最近的点。他的正负超平面可以继续往上和往下。然后分类错误的会有一个类似成本的间隔。那么我们的问题就转化为了求综合考虑效益和成本的决策超平面。
升维转换就是低维度的超平面无法分类，我们将输入数据转化为高维度的，然后再用高维度的分割超平面。
核技巧不同于升维转换，直接获得高维度的数据差异度。
#### 9.分析一下决策树
答：有多个多个决策标准，每次根据一个决策标准产生不同的方向。关键使用基尼系数来确定当前使用什么决策标准。基尼系数是来衡量选择标准的不确定性的，基尼系数怎么求见下图（注意选了一个标准之后剩下的基尼系数需要重新进行计算）。决策树容易造成过拟合，需要进行一些剪枝来去除一些标准。
![image](https://user-images.githubusercontent.com/78149477/185525922-8552fdec-bb9e-4e89-92b3-db54021c1d50.png)
#### 10.分析一下随机森林（多个决策树，每个决策树都只能看到部分数据，最终将每个决策树的结果整合起来）
#### 11.分析一下朴素贝叶斯（就是条件概率，拉普拉斯平滑技巧，就是在每一个关键词的上面默认有一个次数）
![image](https://user-images.githubusercontent.com/78149477/185534716-383cd857-dc41-4cfc-b0df-f756ab013cd6.png)
#### 12.英文面试交流（seu）
（1）.介绍你的家乡
（2）.介绍你的爱好
（3）.英文自我介绍简历

3.good morning, dear distinguished teacher.it is my honor to take part in this interview。
My name is jishengpeng。I am a student majoring in Software engineering in Jilin University。
And I get national scholarship in my college life;
In the following time，I will mainly introduce my scientific research experience。
I have two papers。One of the papers is in the delivery state。It is a CCFA conference paper that the conference is INFOCOM。The main content of the paper is about Neural network architecture search（NAS），which is a very hot and cutting-edge direction in the field of deep learning and network intelligence。The name of paper is ‘’’。We design an architecture .the architecture can automatically design the neural network for multi objects according to different datasets。I was responsible for most of the work。
Another paper was accepted。This is a CCFB Chinese journal paper. The name of the paper is College Entrance Examination volunteer recommendation system based on score prediction. I was mainly responsible for data mining and the establishment of prediction models。The part of the prediction is also about neural network and deep learning.
That is my situation。Thank you for your listening.

2.I live in nantong.it is in the east of Jiangsu province and it is very close to shanghai。Nantong has a very beautiful natural landscape。Such as Langshan and haohe. People in Nantong are also very enthusiastic. We are glad to try our best to help others. If I choose plane/train as my vehicle. It will take me ** hours from nantong to ****.

#### 13.分析一下特征值，特征向量，矩阵地秩，向量组的秩，向量组的极大无关组，线性相关和线性无关，求逆矩阵的方法。
#### 14.说一下你的论文的题目(seu)
《基于分数线预测的多特征融合高考志愿推荐算法》
《self-growing neural network for multi-object network classification》




