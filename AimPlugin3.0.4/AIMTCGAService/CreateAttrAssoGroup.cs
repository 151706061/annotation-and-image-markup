#region License

//L
// 2007 - 2013 Copyright Northwestern University
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
//L

#endregion

namespace AIMTCGAService
{
    class CreateQRAttrAssoGroup
    {
        static public QueryRequestCqlQuery createQueryRequestCqlQuery(string name, string[] queryModifierItems, ItemsChoiceType[] queryModifierItemsChoiceType1,
                                                        Association targetAssociation, Group targetGroup)
        {
            QueryRequestCqlQuery arg = new QueryRequestCqlQuery();
            arg.CQLQuery = new CQLQuery();
            arg.CQLQuery.Target = new Object();
            arg.CQLQuery.Target.name = name;
            if ((queryModifierItems != null) && (queryModifierItemsChoiceType1 != null))
            {
                arg.CQLQuery.QueryModifier = new QueryModifier();
                arg.CQLQuery.QueryModifier.countOnly = false;
                arg.CQLQuery.QueryModifier.Items = queryModifierItems;
                arg.CQLQuery.QueryModifier.ItemsElementName = queryModifierItemsChoiceType1;
            }
            if (targetAssociation != null)
                arg.CQLQuery.Target.Item = targetAssociation;
            else if (targetGroup != null)
                arg.CQLQuery.Target.Item = targetGroup;

            return arg;
        }

        public static Attribute createAttribute(string name, Predicate predicate, string value)
        {
            if (name.Equals(null) || predicate.Equals(null) || value.Equals(null))
                return null;
            Attribute attr1 = new Attribute();
            attr1.name = name;
            attr1.predicate = predicate;
            attr1.value = value;
            return attr1;
        }

        public static Association createAssociation(string name, string rolename, Group group, Attribute attr, Association association)
        {
            Association asso = new Association();
            asso.name = name;
            asso.roleName = rolename;
            if (group != null)
                asso.Item = group;
            else if (attr != null)
                asso.Item = attr;
            else if (association != null)
                asso.Item = association;
            return asso;
        }

        public static Group createGroup(Attribute attr, LogicalOperator logicalOperator)
        {
            return createGroup(new object[] { attr }, logicalOperator);
        }

        public static Group createGroup(Association asso, LogicalOperator logicalOperator)
        {
            return createGroup(new object[] { asso }, logicalOperator);
        }

        public static Group createGroup(object[] items, LogicalOperator logicalOperator)
        {
            Group gr1 = new Group();
            gr1.logicRelation = logicalOperator;
            gr1.Items = items;
            return gr1;
        }
    }
}
