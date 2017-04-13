class MassBin : public MassShape {
public:
// Constructor.
// Params: the lower and upper mass values of the bin.
MassBin(double l_edge, double u_edge) :
    // ... initialize parameters and base class ...
    T_(RealCachedValue::create(*this))
{
    // Add parameters to the model.
    addParameter(LowerEdge_); £!\label{line:addParameter}!£
    addParameter(UpperEdge_);
}

// Public interface to access the lower bin edge.
const shared_ptr<const PositiveRealParameter> lowerEdge()
{ return LowerEdge_; }

// ...

// Calculate the mass-shape on the data partition.
// 1 if the DataPoint mass is in the bin, 0 otherwise.
void calculate(DataPartition& D,
    const shared_ptr<const ParticleCombination>& pc,
    unsigned si) const override {
    // ...
}

private:
// Lower edge of the bin.
const shared_ptr<PositiveRealParameter> LowerEdge_;
// Upper edge of the bin.
const shared_ptr<PositiveRealParameter> UpperEdge_;
// Cached value of the dynamic amplitude.
const shared_ptr<RealCachedValue> T_;
};
